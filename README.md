General Approach
This project aims to help you understand the inner workings of a Unix shell by implementing your own simplified version of it. Here is a general outline of steps you might want to follow to create your shell, along with some explanations and considerations for each step. However, please note that implementing a shell is a complex task, so this is just a high-level guide to get you started.

Here's a general approach you could take:

Understanding the Basics:

Start by thoroughly understanding the Unix shell, its purpose, and how it interacts with the operating system.
Research the history of Unix, the Thompson shell, and Ken Thompson's contributions.
Setting Up the Project:

Create a directory for your shell project.
Choose your preferred text editor (vi, vim, emacs) for coding.
Set up version control (e.g., Git) and create an initial commit.
Building the Shell:

Create a main loop that reads and processes user input.
Split the user input into tokens (words) using the strtok function.
Implement a mechanism to execute simple commands (without arguments) using the execve system call.
Managing Commands and Built-in Functions:

Create a function to search for and execute external programs based on the PATH environment variable.
Implement built-in functions (e.g., exit, cd) by directly invoking appropriate system calls.
Piping and Redirection:

Implement basic support for piping commands using the pipe and dup2 system calls.
Handle input and output redirection using the open and close system calls.
Running in Interactive and Batch Mode:

Detect whether your shell is running interactively or reading from a file (batch mode).
Handle both cases appropriately by modifying the main loop behavior.
Environment Variables and Process Control:

Understand the concept of environment variables and how they affect processes.
Manage environment variables and the environment of the current process using getenv and related functions.
Learn about process IDs (PIDs) and parent process IDs (PPIDs) and how they relate to process control.
Error Handling and Reporting:

Implement error messages that are consistent with the specified output format.
Handle scenarios where commands are not found, system calls fail, etc.
Memory Management and Cleanup:

Use dynamic memory allocation (e.g., malloc, free) where necessary and ensure there are no memory leaks.
Clean up any resources (e.g., file descriptors) before the shell exits.
Documentation and Testing:

Write a comprehensive README.md file that explains how to use your shell and its features.
Write comments in your code to explain complex logic or implementation details.
Test your shell against various scenarios, including commands, piping, redirection, and edge cases.
Ensure your shell's error messages match those of /bin/sh.
Style and Compliance:

Format your code according to the Betty style guidelines.
Make sure your code compiles without errors or warnings using the specified compilation flags.
Submission:

Prepare your project for submission by creating an AUTHORS file and the required repository structure.
Double-check that you've followed all the specified requirements and guidelines.
Remember that creating a shell is a substantial project that involves working with system calls, managing processes, handling I/O, and more. Take your time to understand each concept and gradually build up your shell's functionality. If you encounter specific issues or questions during the process, feel free to ask for help or clarification. Good luck with your project!

Simple Shell Project
This is a simple shell project implemented in the C programming language. The shell is capable of executing basic commands, handling built-in functions, and managing environment variables.

Files and Descriptions
File Name	Description
builtin_functions.c	Contains implementations of various built-in functions.
builtin_finder.c	Implements the function _find_builtin to search for built-in functions.
main_shell.c	Entry point for the shell program, handling user input, command execution, and environment variables.
environment_functions.c	Implements functions related to environment variables and path handling.
print_functions.c	Implements functions for character and string output.
simple_shell.h	Header file defining structures, function prototypes, and includes.
strings_functions.c	Provides string manipulation functions such as length calculation and concatenation.
tok_execute_realloc_free.c	Contains utility functions for tokenization, execution, memory reallocation, and freeing memory.
Usage
Compile the project using the provided compilation command:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Run the shell using the compiled executable:

./hsh
The shell supports interactive and non-interactive modes and provides basic command execution capabilities.

List of allowed functions and system calls
access (man 2 access)

chdir (man 2 chdir)

close (man 2 close)

closedir (man 3 closedir)

execve (man 2 execve)

exit (man 3 exit)

_exit (man 2 _exit)

fflush (man 3 fflush)

fork (man 2 fork)

free (man 3 free)

getcwd (man 3 getcwd)

getline (man 3 getline)

getpid (man 2 getpid)

isatty (man 3 isatty)

kill (man 2 kill)

malloc (man 3 malloc)

open (man 2 open)

opendir (man 3 opendir)

perror (man 3 perror)

read (man 2 read)

readdir (man 3 readdir)

signal (man 2 signal)

stat (__xstat) (man 2 stat)

lstat (__lxstat) (man 2 lstat)

fstat (__fxstat) (man 2 fstat)

strtok (man 3 strtok)

wait (man 2 wait)

waitpid (man 2 waitpid)

wait3 (man 2 wait3)

wait4 (man 2 wait4)

write (man 2 write)

GOOD LUCK

