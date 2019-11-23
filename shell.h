#ifndef SHELL_H
#define SHELL_H

#define BUFFERSIZE 1024
#define DELIMINATOR "\n\r\t\a "

extern char **environ;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void call_cd (char **args);
int call_exit (char *args);
int call_exit_status(char **args);
int call_env (char **args);
int call_help(char *args);

int _isdigit(char str);
int _exit_atoi(char *str);


char **parse_line(char *line);

int function_filter (char **commands, char **env);

int exec_cmd (char **str, char **env);
char *read_line(void);
char *_strcat(char *s1, char *s2);
void ctrl_c_handler(int sig_num);

int _atoi(char *str);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
