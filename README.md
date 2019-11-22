# Simple Shell
by Ezra Nobrega & Geoffrey Zoref
![Shell Commands](https://www.guru99.com/images/ShellScripting.png)

Task: Write a simple UNIX command interpreter.

## 0. README, man, AUTHORS
  - Write a README for your shell
    - Write a man for your shell.
      - You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## 1. Betty would be proud mandatory
Write a beautiful code that passes the Betty checks

## 2. Test suite
- Every team (who contributed) will get the same score for this task (The repository owner will not get more points)
You have to be pro-active and agree on one and unique repository to use for the test suite
- Please provide the link to the repository you contributed to
- Your contribution must be relevant (Correcting typos is nice and always appreciated on the open source sphere, but we won’t consider this a contribution at this point, unless it fixes a bug)

## 3. Simple shell 0.1
Write a UNIX command line interpreter.
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

## 4. Simple shell 0.1.1
- Write your own getline function
- Use a buffer to read many chars at once and call the least possible the read system call
- You will need to use static variables
- You are not allowed to use getline

## 5. Simple shell 0.2
- Handle command lines with arguments

## 6. Simple shell 0.2.1
- You are not allowed to use strtok

## 7. Simple shell 0.3
- Handle the PATH

## 8. Simple shell 0.4
- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

## 9. Simple shell 0.4.1
- handle arguments for the built-in exit
- Usage: exit status, where status is an integer used to exit the shell

## 10. Simple shell 0.4.2
- Handle Ctrl+C: your shell should not quit when the user inputs ^C

## 11. Simple shell 1.0
- Implement the env built-in, that prints the current environment

## 12. setenv, unsetenv
Implement the setenv and unsetenv builtin commands
* setenv
    * Initialize a new environment variable, or modify an existing one
        * Command syntax: setenv VARIABLE VALUE
	    * Should print something on stderr on failure

* unsetenv
    *  Remove an environment variable
        * Command syntax: unsetenv VARIABLE
	    * Should print something on stderr on failure

## 13. cd
Implement the builtin command cd:

- Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
- If no argument is given to cd the command must be - interpreted like cd $HOME
- You have to handle the command cd -
- You have to update the environment variable PWD when you change directory

## 14. ;
- Handle the commands separator ;

## 15. && and ||
- Handle the && and || shell logical operators

## 16. alias
* Implement the alias builtin command
* Usage: alias [name[='value'] ...]
    * alias: Prints a list of all aliases, one per line, in the form name='value'
        * alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
	    * alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

## 17. Variables
- Handle variables replacement
- Handle the $? variable
- Handle the $$ variable

## 18. Comments
- Handle comments (#)

## 19. help
- Implement the help built-in
- Implement the help built-in

## 20. history
- Implement the history built-in, without any argument
The history built-in displays the history list, one command by line, preceded with line numbers (starting at 0)
- On exit, write the entire history, without line numbers, to a file named .simple_shell_history in the directory $HOME
- When the shell starts, read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096

## 21. File as input
- Usage: simple_shell [filename]
- Your shell can take a file as a command line argument
- The file contains all the commands that your shell should run before exiting
- The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin

## 22. What happens when you type ls -l in the shell
Write a blog post describing step by step what happens when you type ls -l and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).


| File name | Functions in file|
| ------ | ------ |
| [**main.c**](main.c) |``` main(int argc, char **argv, char **env) ```
|        |``` void cntl_c_handler(void)```
| [**read_line.c**](read_line.c) | ```char *readline(void)``` |
| [**parse.c**](parse.c) |```char **parse_line(char *line)``` |
| [**filter.c**](filter.c) | ```int function_filter(char **commands, char **env)```  |
| [**built_ins.c**](built_ins.c) | ```int call_exit(char *args)```  |
|             | ```int call_cd(char *args)```  |
|             | ```int call_help(char *args)```  |
| [**call_exec.c**](call_exec.c) | ```int exec_cmd(char *str, char **env)``` |
|             | ```int find_path(char **environment)```  |