#ifndef SHELL_H
#define SHELL_H

typedef struct format
{
	char *id;
	int (*f)(char **address);
} cmd_fo;

#define BUFFERSIZE 1024
#define DELIMINATOR " "

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

int call_cd (char **str);
int call_exit (char **str);
int call_env (char **str);

char **parse_line(char *line);
int function_filter (char **str, char **env);
int exec_cmd (char **str, char **env);
char *read_line(void);
#endif
