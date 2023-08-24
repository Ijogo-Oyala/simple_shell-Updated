#include "simple_shell.h"

/**
 * _find_builtin - Finds and returns a built-in function pointer.
 * @com: Command to check if it's a built-in command.
 * Return: Pointer to a function that takes arguments and returns void.
 */
void(*_find_builtin(char **com))(char **com)
{
	int builtin_index, char_index;

	/* Array of built-in commands along with their corresponding functions */
	built_in C[] = {
		{"exit", _exit_},
		{"env", _env_},
		{"setenv", _set_env},
		{"unsetenv", _unset_env},
		{NULL, NULL}
	};

	/* Iterate through the array of built-in commands */
	for (builtin_index = 0; C[builtin_index].com_name; builtin_index++)
	{
		char_index = 0;
		/* Compare the first chars of the input command and the built-in command */
		if (C[builtin_index].com_name[char_index] == com[0][char_index])
		{
			/* Compare the full strings character by character */
			for (char_index = 0; com[0][char_index]; char_index++)
			{
				if (C[builtin_index].com_name[char_index] != com[0][char_index])
					break;
			}

			/* If the loop completed without a mismatch, the command is found */
			if (!com[0][char_index])
				return (C[builtin_index].function);
		}
	}
	/* If the command is not found, return NULL */
	return (0);
}

