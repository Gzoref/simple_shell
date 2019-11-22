#ifndef SHELL_H
#define SHELL_H

typedef struct format
{
	char *id;
	int (*f)(char *str);
} cmd_fo;

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

int call_cd (char **arg);
int call_exit (char *arg);
int call_env (char *arg);

char **parse_line(char *line);

int function_filter (char **commands, char **env);

int exec_cmd (char **str, char **env);
char *read_line(void);
char *_strcat(char *s1, char *s2);
void cntl_c_handler();


int _strcmp(char *str1, char *str2);
int _strlen(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
