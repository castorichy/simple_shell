# simple_shell

![simple shell](https://s31.postimg.org/403ix8w7f/j1_IPt_Uu_IS51_N62_LB5z9_Qhg_r.jpg)


## Table of Contents

* [Description](#description)
* [Purpose](#purpose)
* [Requirements](#requirements)
* [File Structure](#file-structure)
* [Usage](#usage)
* [Examples](#examples)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)


## Description

**Simple_shell** Write a Simple UNIX command interpreter

## Purpose

The purpose of the simple shell project is to understand:
* how a shell works
* PID and PPIDs
* how processes are created
* the three prototypes of `main`
* how the shell uses the `PATH` to find and execute programs
* the `EOF`/"end-of-file" condition

## Requirements

* Must follow [Betty](https://github.com/holbertonschool/Betty/wiki) style and document guidelines
* Allowed editors: `vi`, `vim`, `emacs`
* Must have a `README.md` file
* All header files must be include guarded
* No more than 5 functions per files
* All your header files should be include guarded
* Use system calls only when you need to [why?](https://alx-intranet.hbtn.io/rltoken/EU7B1PTSy14INnZEShpobQ)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://alx-intranet.hbtn.io/rltoken/UL8J3kgl7HBK_Z9iBL3JFg)

## File Structure

* [AUTHORS](https://github.com/castorichy/simple_shell/blob/docs/AUTHORS) - list of contributors
* [check_helpers.c](https://github.com/Annetaliya/simple_shell/blob/docs/check_helpers.c) - helper functions that check for builtins
  * `exit_check` - checks if user_input is `exit`
  * `blank_check` - checks if user_input is `\n`
  * `env_check` - checks if user_input is `env`
* [env_helpers.c](env_helpers.c) - helper functions related to PATH and other environment variables
  * `get_path_count` - gets count of path parts
  * `get_path_array` - tokenizes path to 2d array
  * `find_path` - finds and checks path for given command
  * `print_env` - shell builtin that prints current environment
* [error_helpers.c](error_helpers.c) - helper functions that print appropriate error messages
  * `command_error` - command not found error
  * `exec_error` - command could not execute error
  * `access_error` - user does not have permission to execute command
  * `exit_error` - user has entered an invalid exit code
* [fork_wait_exec.c](fork_wait_exec.c) - process and execution function
* [memory_helpers.c](memory_helpers.c) - helper functions related to memory management
  * `free_array` - 2D array freeing function
* [man_1_simple_shell](man_1_simple_shell) - manual page
* [number_helpers.c](number_helpers.c) - helper functions pertaining to integers
  * `_atoi` - turns a numerical string into an integer
  * `print_number` - prints an integer to standard output
* [parse.c](parse.c) - command and argument parsing function
  * `is_cmd` - determines if a file is an executable command
  * `dup_chars` - duplicates characters
  * `find_path` - finds this cmd in the PATH string
* [realloc.c](realloc.c) - Memory allocation
  * `*_memset` - fills memory with a constant byte
  * `ffree` - frees a string of strings
  * `_realloc` - reallocates a block of memory
* [shell.h](shell.h) - header file
* [shell_loop.c](shell_loop.c) - shell loop
  * `hsh` - main shell loop
  * `find_builtin` - finds a builtin command
  * `find_cmd` - finds a command in PATH
  * `fork_cmd ` - forks a an exec thread to run cmd
* [string1.c](string1.c) - helper functions pertaining to string handling
  * `_strlen` - finds length of a string
  * `_strcmp` - compares two strings
  * `_strdup` - duplicates two strings (including memory management)
  * `_puts` - prints an input string
  * `_putchar` - writes a single character to standard output
* [tokenizer.c](tokenizer.c) - word splitting function helpers
  * `*strtow` - splits a string into words. Repeat delimiters are ignored
  * `**strtow2` - splits a string into words
* [list.c](list.c) - list functions for strings and nodes
  * `list_len` - determines length of linked list
  * `list_to_strings` - returns an array of strings of the list->str
  * `print_list` - prints all elements of a list_t linked list
  * `node_starts_with` - returns node whose string starts with prefix
  * `get_node_index` - gets the index of a node
* [main.c](main.c) - Main function
* [memory.c](memory.c) - frees a pointer and NULLs the address
* [vars.c](vars.c) - vars helpers
  * `is_chain ` - test if current char in buffer is a chain delimeter
  * `check_chain` - checks we should continue chaining based on last status
  * `replace_alias` - replaces an aliases in the tokenized string
  * `replace_vars` - replaces vars in the tokenized string
  * `replace_string` - replaces string
## Compilation

```gcc -Wall -Wextra -Werror -pedantic *.c -o hsh```
*GCC 4.8.4 or later only*
## Usage Examples
### Interactive Mode
```c
$ ./hsh
($) /bin/sh
hsh main.c shell.c 
($)
($) exit
$
```

### Non-Interactive Mode

```c
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Bugs
At this time, there are no known bugs.
## Authors
Duncan Kipruto | [GitHub](https://github.com/castorichy) | [Twitter](https://twitter.com/geecoding)
Annette Adhiambo | [GitHub](https://github.com/mjkamma) | [Twitter](https://twitter.com/PeaceJones8)
## License
**simple_shell** is open source and free to download and use
