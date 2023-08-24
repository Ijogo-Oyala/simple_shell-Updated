#include "simple_shell.h"

/**
 * ctrl_c_handler - Handles the SIGINT signal (Ctrl+C).
 * @signal_number: Integer representing the signal number.
 */
void ctrl_c_handler(int signal_number)
{
	if (signal_number == SIGINT)
	{
		/* Print a new prompt after Ctrl+C is pressed */
		_puts_("\n#GshellX$ ");
	}
}

/**
 * handle_eof - Handles the End of File condition.
 * @line_length: Return value of the getline function.
 * @buffer: Buffer.
 */
void handle_eof(int line_length, char *buffer)
{
	(void)buffer; /* Unused parameter */
	if (line_length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts_("\n"); /* Print a newline if input comes from a terminal */
			free(buffer); /* Free allocated buffer memory */
		}
		exit(0); /* Exit the program */
	}
}

/**
 * _isatty_ - Checks if the program is running in a terminal.
 */
void _isatty_(void)
{
	if (isatty(STDIN_FILENO))
	{
		/* Print a new prompt if running in a terminal */
		_puts_("#GshellX$ ");
	}
}

/**
 * main - Entry point for the Shell program.
 * Return: 0 on success.
 */
int main(void)
{
	/* Initialize variables */
	ssize_t input_length = 0;
	char *input_buffer = NULL, *path_value, *executable_path, **arguments;
	size_t buffer_size = 0;
	path_dir *path_list = '\0';
	/* Pointer to a function that takes an array of strings (char**) as an argument.
 	* This pointer is used to point to built-in functions or external commands
  	* that the shell may execute based on user input.
  	*/
	void (*command_function)(char **);

	/* Set up signal handler for Ctrl+C */
	signal(SIGINT, ctrl_c_handler);
	/* Main shell loop */
	while (input_length != EOF)
	{
		/* Check if running in a terminal and print the prompt */
		_isatty_();
		/* Get input from the user */
		input_length = getline(&input_buffer, &buffer_size, stdin);
		/* Handle End of File (EOF) */
		handle_eof(input_length, input_buffer);
		/* Split the input into individual arguments */
		arguments = split_string(input_buffer, " \n");
		if (!arguments || !arguments[0])
			_execute(arguments);
		else
		{
			/* Get the value of the PATH environment variable */
			path_value = _get_env("PATH");
			/* Create a linked list of path directories */
			path_list = link_path_dir(path_value);
			/* Find the executable path for the given command */
			executable_path = _which_(arguments[0], path_list);
			/* Find if the command is a built-in function */
			command_function = _find_builtin(arguments);
			if (command_function)
			{
				/* If it's a built-in command, execute it */
				free(input_buffer);
				command_function(arguments);
			}
			else if (!executable_path)
				_execute(arguments); /* If the command is not found, execute it */
			else if (executable_path)
			{
				/* If the command is found, replace the argument and execute */
				free(arguments[0]);
				arguments[0] = executable_path;
				_execute(arguments);
			}
		}
	}
	/* Clean up and free memory */
	free_path_list(path_list);
	free_arv(arguments);
	free(input_buffer);
	return (0);
}
