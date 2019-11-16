#ifndef SHELL_H
#define SHELL_H

typedef struct format
{
	char *id;
	int (*f)(char **address)
} cmd_fo;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int call_cd (char **str);
int call_exit (char **str);
int call_env (char **str);

int exec_cmd (char **);
#endif
