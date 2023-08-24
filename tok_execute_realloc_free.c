#include "simple_shell.h"

/**
 * _realloc_ - Reallocates memory block with a new size.
 * @prev_ptr: Pointer to the previous memory block.
 * @old_size: Previous size of the memory block.
 * @new_size: New size for the memory block.
 * Return: Pointer to the newly resized memory block.
 */
void *_realloc_(void *prev_ptr, unsigned int old_size, unsigned int new_size)
{
	char *old_ptr;
	char *new_ptr;

	unsigned int j;
	/* If previous pointer is NULL, allocate new memory */
	if (prev_ptr == NULL)
		return (malloc(new_size));
	/* If new size is the same as old size, return previous pointer */
	if (new_size == old_size)
		return (prev_ptr);
	/* If new size 0 & prev pointer isnt NULL, free memory and return NULL */
	if (new_size == 0 && prev_ptr != NULL)
	{
		free(prev_ptr);
		return (NULL);
	}
	/* Allocate memory for the new size */
	new_ptr = malloc(new_size);
	old_ptr = prev_ptr;

	if (new_ptr == NULL)
		return (NULL);
	/* Copy data from old pointer to new pointer */
	if (new_size > old_size)
	{
		for (j = 0; j < old_size; j++)
			new_ptr[j] = old_ptr[j];
		free(prev_ptr);
		for (j = old_size; j < new_size; j++)
			new_ptr[j] = '\0';
	}
	if (new_size < old_size)
	{
		for (j = 0; j < new_size; j++)
			new_ptr[j] = old_ptr[j];
		free(prev_ptr);
	}
	return (new_ptr);
}


/**
 * split_string - Splits a string and creates an array of pointers to words.
 * @str: The string to be split.
 * @delim: The delimiter to split the string.
 * Return: An array of pointers to words.
 */
char **split_string(char *str, const char *delim)
{
	int index, w_cnt;
	char **w_arr;
	char *tokens, *str_copy;
	/* Create a copy of the input string to avoid modifying the original */
	str_copy = malloc(str_len(str) + 1);
	if (str_copy == NULL)
	{
		perror(_get_env("_"));
		return (NULL);
	}
	index = 0;
	while (str[index])
	{
		str_copy[index] = str[index];
		index++;
	}
	str_copy[index] = '\0';
	/* Get the first token */
	tokens = strtok(str_copy, delim);
	/* Initialize the word array with the first token */
	w_arr = malloc(sizeof(char *) * 2);
	w_arr[0] = str_dup(tokens);

	index = 1;
	w_cnt = 3;
	/* Loop through the remaining tokens and add them to the word array */
	while (tokens)
	{
		tokens = strtok(NULL, delim);
		/* Resize the word array and add the token */
		w_arr = _realloc_(w_arr,(sizeof(char *)*(w_cnt - 1)),(sizeof(char *)*w_cnt));
		w_arr[index] = str_dup(tokens);

		index++;
		w_cnt++;
	}
	free(str_copy); /* Free the copied string */
	return (w_arr);
}

/**
 * _execute - Executes a command.
 * @args: Array of arguments.
 */
void _execute(char **args)
{
	int child_pid, status;

	/* Check if arguments or command are missing */
	if (!args || !args[0])
		return;

	/* Create a child process using fork */
	child_pid = fork();
	if (child_pid == -1)
		perror(_get_env("_"));

	/* Child process code */
	if (child_pid == 0)
	{
		/* Execute the command with provided arguments */
		execve(args[0], args, environ);
			perror(args[0]); /* Print an error message if execution fails */
		exit(EXIT_FAILURE);
	}
	/* Parent process waits for the child to complete */
	wait(&status);
}


/**
 * free_arv - Frees the array of pointers.
 * @arv: Array of pointers.
 */
void free_arv(char **arv)
{
	int index;

	/* Iterate through the array and free each element */
	for (index = 0; arv[index]; index++)
		free(arv[index]);

	/* Free the array itself */
	free(arv);
}

