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
	ssize_t input_length = 0;
	char *input_buffer = NULL, *path_value, *executable_path, **arguments;
	size_t buffer_size = 0;
	path_dir *path_list = '\0';
	void (*command_function)(char **);

	signal(SIGINT, ctrl_c_handler); /* Set signal handler for Ctrl+C */
	while (input_length != EOF) /* Main shell loop */
	{
		_isatty_(); /* Check if running in terminal & print prompt */
		input_length = getline(&input_buffer, &buffer_size, stdin); /* Get input  */
		handle_eof(input_length, input_buffer);
		arguments = split_string(input_buffer, " \n"); /* Split input to ind args */
		if (!arguments || !arguments[0])
			_execute(arguments);
		else
		{
			path_value = _get_env("PATH"); /* Get value of PATH env var */
			path_list = link_path_dir(path_value); /* Create linked list of path dir */
			executable_path = _which_(arguments[0], path_list); /* Find exe path com */
			command_function = _find_builtin(arguments); /* Find com is builtin func */
			if (command_function)
			{
				free(input_buffer); /* If built-in command, execute */
				command_function(arguments);
			}
			else if (!executable_path)
				_execute(arguments); /* If the command is not found, execute it */
			else if (executable_path)
			{
				free(arguments[0]); /* If comm found, replace arg & execute */
				arguments[0] = executable_path;
				_execute(arguments);
			}
		}
	}
	free_path_list(path_list); /* Clean up and free memory */
	free_arv(arguments);
	free(input_buffer);
	return (0);
}
