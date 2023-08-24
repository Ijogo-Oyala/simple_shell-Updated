#include "simple_shell.h"

/**
 * str_len - Returns the length of a string
 * @str: Pointer to the string
 * Return: Length of the string
 */
int str_len(const char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		counter++;
		str++;
	}

	return (counter);
}

/**
 * str_dup - Duplicates a string.
 * @str: Pointer to the source string.
 *
 * Return: Pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *str_dup(const char *str)
{
	int i, length;
	char *duplicated_str;

	/* Check if the input string is NULL */
	if (!str)
		return (NULL);

	/* Calculate the length of the input string */
	length = 0;
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicated string */
	duplicated_str = malloc(sizeof(char) * (length + 1));
	if (!duplicated_str)
		return (NULL);

	/* Copy characters from the source string to the duplicated string */
	for (i = 0; i < length; i++)
		duplicated_str[i] = str[i];

	duplicated_str[length] = str[length]; /* = '\0' */
	return (duplicated_str);
}
/**
 * str_concat - Concatenates three strings into a newly allocated memory.
 * @prefix: First string
 * @separator: Second string
 * @suffix: Third string
 *
 * Return: Pointer to the concatenated string
 */
char *str_concat(char *prefix, char *separator, char *suffix)
{
	char *results;
	int len_prefix, len_separator, len_suffix, i, idx;

	len_prefix = str_len(prefix);
	len_separator = str_len(separator);
	len_suffix = str_len(suffix);

	results = malloc(len_prefix + len_separator + len_suffix + 1);
	if (!results)
		return (NULL);

	for (i = 0; prefix[i]; i++)
		results[i] = prefix[i];
	idx = i;

	for (i = 0; separator[i]; i++)
		results[idx + i] = separator[i];
	idx += i;

	for (i = 0; suffix[i]; i++)
		results[idx + i] = suffix[i];

	results[idx + i] = '\0';

	return (results);
}

