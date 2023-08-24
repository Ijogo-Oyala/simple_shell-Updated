#include "simple_shell.h"

/**
 * _exit_ - Exits the shell with or without a specified return status.
 * @args: Array of words from the entered line.
 */
void _exit_(char **args)
{
	int index, return_status;

	if (args[1])
	{
		return_status = _atoi_(args[1]);
		/* Ensure return status is not negative */
		if (return_status <= -1)
			return_status = 2;
		/* Free the array of arguments and exit with specified status */
		free_arv(args);
		exit(return_status);
	}

	/* Free memory and exit with status 0 */
	for (index = 0; args[index]; index++)
		free(args[index]);
	free(args);
	exit(0);
}

/**
 * _atoi_ - Converts a string to an integer.
 * @str: Pointer to the string to be converted.
 * Return: The converted integer.
 */
int _atoi_(char *str)
{
	int index, result, sign = 1;

	index = 0;
	result = 0;
	/* Skip non-digit characters until a digit or end of string is found */
	while (!((str[index] >= '0') && (str[index] <= '9')) && (str[index] != '\0'))
	{
		if (str[index] == '-')
		{
			/* Toggle the sign for negative numbers */
			sign = sign * (-1);
		}
		index++;
	}
	/* Convert consecutive digit characters to an integer */
	while ((str[index] >= '0') && (str[index] <= '9'))
	{
		result = (result * 10) + (sign * (str[index] - '0'));
		index++;
	}
	return (result);
}

/**
 * _env_ - Prints the current environment variables.
 * @args: Array of arguments (unused in this case).
 */
void _env_(char **args __attribute__ ((unused)))
{
	int index;
	/* Loop through the environment variables and print each one */
	for (index = 0; environ[index]; index++)
	{
		_puts_(environ[index]);
		_puts_("\n"); /* Print a newline after each environment variable */
	}
}

