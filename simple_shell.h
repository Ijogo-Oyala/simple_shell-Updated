#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

/*---string functions---*/
int str_len(const char *str);
char *str_dup(const char *str);
char *str_concat(char *prefix, char *separator, char *suffix);

/*---print functions---*/
int _putchar_(char ch);
void _puts_(const char *string);

/*--- reallocate memory ---*/
void *_realloc_(void *prev_ptr, unsigned int old_size, unsigned int new_size);
/*--- split string ---*/
char **split_string(char *str, const char *delim);
/*--- execute function ---*/
void _execute(char **args);


extern char **environ;

/**
 * struct path_directory - Represents a directory in PATH with additional info.
 * @dir: Directory path.
 * @next: Pointer to the next node in the list.
 */
typedef struct path_directory
{
    char *dir;
    struct path_directory *next;
} path_dir;

/*--- pathfinder functions ---*/
char *_get_env(const char *variable_name);
path_dir *add_path_node_end(path_dir **head, char *dir);
path_dir *link_path_dir(char *path_string);
char *_which_(char *filename, path_dir *path_list);

/**
 * struct built_in - Holds a pointer to a function
 * along with its corresponding built-in command.
 *
 * @com_name: The built-in command's name.
 * @function: A function pointer to execute the corresponding built-in command.
 */
typedef struct built_in
{
	char *com_name;
	void (*function)(char **);
} built_in;

/*--- builtin functions ---*/
int _atoi_(char *str);
void _env_(char **args __attribute__((unused)));
void _set_env(char **args);
void _unset_env(char **args);
void _exit_(char **args);

/*--- builtin finder function ---*/
void(*_find_builtin(char **com))(char **);

/*--- memory leak handling ---*/
void free_arv(char **arv);

void free_path_list(path_dir *head); /*pathfinder.c */


#endif /* SIMPLE_SHELL_H */

