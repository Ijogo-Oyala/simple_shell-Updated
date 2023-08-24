#include "simple_shell.h"

/**
 * _get_env - Gets the value of an environment variable.
 * @variable_name: Name of the environment variable.
 * Return: String value of the environment variable, or NULL if not found.
 */
char *_get_env(const char *variable_name)
{
	int index, char_index;
	char *value;

	/* Return NULL if the variable name is not provided */
	if (!variable_name)
		return (NULL);

	/* Iterate through the environment variables */
	for (index = 0; environ[index]; index++)
	{
		char_index = 0;

		/* Compare each character of the variable name */
		if (variable_name[char_index] == environ[index][char_index])
		{
			while (variable_name[char_index])
			{
				/* Break the loop if characters do not match */
				if (variable_name[char_index] != environ[index][char_index])
					break;

				char_index++;
			}

			/* If the loop reached the end of the variable name, the variable is found */
			if (variable_name[char_index] == '\0')
			{
				/* Get the value of the variable */
				value = (environ[index] + char_index + 1);
				return (value);
			}
		}
	}

	/* Return 0 if the variable is not found */
	return (0);
}

/**
 * add_path_node_end - Adds a new node at the end of a path_dir list.
 * @head: Pointer to pointer to the linked list.
 * @dir: Directory path to be added.
 * Return: Address of the new element/node.
 */
path_dir *add_path_node_end(path_dir **head, char *dir)
{
	path_dir *tmp_node; /* Temporary pointer for traversal */
	path_dir *new_node; /* New node to be added */

	new_node = malloc(sizeof(path_dir)); /* Allocate memory for new node */

	if (!new_node || !dir)
	{
		return (NULL); /* Return NULL if allocation fails or dir is NULL */
	}

	new_node->dir = dir; /* Set the directory path in the new node */
	new_node->next = '\0'; /* Initialize the next pointer to NULL (char) */

	if (!*head)
	{
		*head = new_node; /* If the list is empty, make the new node the head */
	}
	else
	{
		tmp_node = *head; /* Start traversal from the head */

		while (tmp_node->next)
		{
			tmp_node = tmp_node->next; /* Move to the last node */
		}

		tmp_node->next = new_node; /* Link the new node to the last node */
	}

	return (*head); /* Return the updated head of the list */

}

