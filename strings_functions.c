#include "shell.h"

/**
 * str_len - Returns the length of a string
 * @str: Pointer to the string
 * Return: Length of the string
 */
int str_len(const char *str)
{
	size_t counter = 0;

	while (*str != '\0')
	{
		counter++;
		str++;
	}

	return (counter);
}

