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


## Example

```c
$ pwd
Output: /home/simple_shell
```

```c
$ ls
AUTHORS  WhoAmI.txt  /backups  built_ins.c  easter_egg1.c  env.c  filter.c  local.h memory_utils.c  read_line.c  shell.h  str_utils1.c  str_utils3.c  README.md  a.out       bin_ls.bash  call_exec.c  emacs  file.txt  hsh  main.c  parse.c  setenv.c simple_shell_man  str_utils2.c  testShell.bash
```

```c
$ ls -la
total 264
drwxr-xr-x 1 root root  4096 Nov 26 11:17 .
drwxr-xr-x 1 root root  4096 Nov 25 10:55 ..
drwxr-xr-x 1 root root  4096 Nov 26 11:17 .git
-rw-r--r-- 1 root root     5 Nov 25 17:01 .gitignore
-rw-r--r-- 1 root root   154 Nov 25 17:01 AUTHORS
-rw-r--r-- 1 root root  5883 Nov 26 11:17 README.md
-rw-r--r-- 1 root root  1075 Nov 25 17:01 WhoAmI.txt
-rwxr-xr-x 1 root root 49960 Nov 25 19:08 a.out
drwxr-xr-x 1 root root  4096 Nov 26 10:32 backups
-rwxr-xr-x 1 root root  3045 Nov 25 19:57 bin_ls.bash
-rw-r--r-- 1 root root  1298 Nov 26 09:54 built_ins.c
-rw-r--r-- 1 root root  3523 Nov 26 10:32 call_exec.c
-rw-r--r-- 1 root root   716 Nov 26 09:54 easter_egg1.c
-rw-r--r-- 1 root root    13 Nov 19 14:38 emacs
-rw-r--r-- 1 root root   383 Nov 26 09:54 env.c
-rw-r--r-- 1 root root  1781 Nov 25 19:01 file.txt
-rw-r--r-- 1 root root  1087 Nov 26 09:54 filter.c
-rwxr-xr-x 1 root root 44376 Nov 26 10:33 hsh
-rw-r--r-- 1 root root   728 Nov 22 11:17 local.h
-rw-r--r-- 1 root root   970 Nov 26 09:54 main.c
-rw-r--r-- 1 root root   630 Nov 26 09:54 memory_utils.c
-rw-r--r-- 1 root root   853 Nov 26 09:54 parse.c
-rw-r--r-- 1 root root   311 Nov 26 09:54 read_line.c
-rw-r--r-- 1 root root  1098 Nov 26 09:54 setenv.c
-rw-r--r-- 1 root root  1609 Nov 26 10:35 shell.h
-rw-r--r-- 1 root root  4756 Nov 26 10:55 simple_shell_man
-rw-r--r-- 1 root root  1539 Nov 26 09:54 str_utils1.c
-rw-r--r-- 1 root root  1681 Nov 26 09:54 str_utils2.c
-rw-r--r-- 1 root root  1003 Nov 26 09:54 str_utils3.c
-rwxr-xr-x 1 root root 13317 Nov 25 19:25 testShell.bash
```
