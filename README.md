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
