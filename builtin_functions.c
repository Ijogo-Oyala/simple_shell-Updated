#include "simple_shell.h"

/**
 * _exit_ - Exits the shell with or without a specified return status.
 * @args: Array of words from the entered line.
 */
void _exit_(char **args)
{
	int index, ret_status;

	if (args[1])
	{
		ret_status = _atoi_(args[1]);
		/* Ensure return status is not negative */
		if (ret_status <= -1)
			ret_status = 2;
		/* Free the array of arguments and exit with specified status */
		free_arv(args);
		exit(ret_status);
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

/**
 * _set_env - Adds or modifies an environment variable.
 * @args: Array of words containing command and arguments.
 */
void _set_env(char **args)
{
	int env_index, name_index, value_index;
	/* Check if the required arguments are provided */
	if (!args[1] || !args[2])
	{
		perror(_get_env("_"));
		return;
	}
	/* Loop existing env var */
	for (env_index = 0; environ[env_index]; env_index++)
	{
		name_index = 0;
		/* Compare the names of the environment variable */
		if (args[1][name_index] == environ[env_index][name_index])
		{
			while (args[1][name_index])
			{
				if (args[1][name_index] != environ[env_index][name_index])
					break;

				name_index++;
			}
			/* If the names match, update the environment variable */
			if (args[1][name_index] == '\0')
			{
				value_index = 0;
				while (args[2][value_index])
				{
					environ[env_index][name_index + 1 + value_index] = args[2][value_index];
					value_index++;
				}
				environ[env_index][name_index + 1 + value_index] = '\0';
				return;
			}
		}
	}
	if (!environ[env_index]) /* If the env var doesn't exist, create new */
	{
		environ[env_index] = str_concat(args[1], "=", args[2]);
		environ[env_index + 1] = '\0';
	}
}

/**
 * _unset_env - Removes an environment variable.
 * @args: Array of entered words.
 */
void _unset_env(char **args)
{
	int env_index, name_index;
	/* Check if the required argument is provided */
	if (!args[1])
	{
		perror(_get_env("_"));
		return;
	}
	/* Loop through the existing environment variables */
	for (env_index = 0; environ[env_index]; env_index++)
	{
		name_index = 0;
		/* Compare the names of the environment variable */
		if (args[1][name_index] == environ[env_index][name_index])
		{
			while (args[1][name_index])
			{
				if (args[1][name_index] != environ[env_index][name_index])
					break;

				name_index++;
			}
			/* If the names match, remove the environment variable */
			if (args[1][name_index] == '\0')
			{
				free(environ[env_index]);
				environ[env_index] = environ[env_index + 1];

				/* Shift the remaining environment variables */
				while (environ[env_index])
				{
					environ[env_index] = environ[env_index + 1];
					env_index++;
				}
				return;

			}
		}
	}
}
