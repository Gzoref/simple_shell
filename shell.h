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
#include <sys/types.h>
#include <sys/wait.h>

int call_cd (char *str);
void call_exit (void);
int call_env (char *str);

char **parse_line(char *line);

int function_filter (char **commands);

int exec_cmd (char **str, char **env);
char *read_line(void);

int _strcmp(char *str1, char *str2);

#endif
