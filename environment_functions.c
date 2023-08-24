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

			/* If loop reached the end of the variable name, the variable is found */
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

/**
 * link_path_dir - Creates a linked list for path directories.
 * @path_string: String containing the PATH value.
 * Return: Pointer to the created linked list.
 */
path_dir *link_path_dir(char *path_string)
{
	path_dir *head = '\0';
	char *tokens;
	char *copied_path = str_dup(path_string); /* Make a copy of the path string */

	tokens = strtok(copied_path, ":"); /* Tokenize the copied path string */
	while (tokens)
	{
		/* Add each directory to the linked list */
		head = add_path_node_end(&head, tokens);
		tokens = strtok(NULL, ":");
	}
	/* Free the copied path string after use */
	free(copied_path);

	return (head);
}
/**
 * _which_ - Finds the pathname of an executable file.
 * @filename: Name of the file or command typed.
 * @path_list: Head of the linked list of path directories.
 * Return: Pathname of the filename or NULL if no match.
 */
char *_which_(char *filename, path_dir *path_list)
{
	struct stat file_stat;
	char *full_path;

	path_dir *current_dir = path_list;

	while (current_dir)
	{
		/* Concatenate directory, "/", and filename */
		full_path = str_concat(current_dir->dir, "/", filename);

		/* Check if the file exists */
		if (stat(full_path, &file_stat) == 0)
			return (full_path); /* Return the full path if the file exists */

		free(full_path); /* Free memory allocated for full path */
		current_dir = current_dir->next; /* Move to the next directory */
	}

	return (NULL); /* Return NULL if the file was not found */
}

/**
 * free_path_list - Frees a linked list of path directories.
 * @head: Pointer to the head of the linked list.
 */
void free_path_list(path_dir *head)
{
	path_dir *temp;

	while (head)
	{
		temp = head->next; /* Store the next node in a temporary variable */
		free(head->dir); /* Free the memory allocated for the directory path */
		free(head); /* Free the memory allocated for the node itself */
		head = temp; /* Move to the next node */
	}
}

