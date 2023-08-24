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

