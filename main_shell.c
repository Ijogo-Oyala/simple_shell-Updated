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

