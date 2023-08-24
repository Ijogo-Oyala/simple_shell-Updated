#include "simple_shell.h"

/**
 * _putchar_ - Writes a character to stdout
 * @ch: The character to write
 *
 * Return: Always 0 (Success)
 */
int _putchar_(char ch)
{
	/* Write the character to stdout & Return success */
	return (write(1, &ch, 1));
}

/**
 * _puts_ - Prints a string to stdout
 * @string: The string to print
 *
 * Return: Always 0 (Success)
 */
void _puts_(const char *string)
{
	int counter;

	counter = 0;

	while (string[counter])
	{
		/* Write the string to stdout one character at a time */
		_putchar_(string[counter]);
		counter++;
	}
}

