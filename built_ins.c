#include "shell.h"

/**
 *  call_exit - Exits shell
 *
 *  @args: passes in char pointer
 *
 *  Return: Integer
 */

int call_exit(char *args)
{
//	exit(EXIT_SUCCESS);
	if (_strcmp(args, "exit") == 0)
		{
			free(args);
			exit(98);
		}
}


/**
 *  call_cd - Change directory
 *
 *  @args: Passes in char pointer
 *
 *  Return: Integer
 */

int call_cd(char **args)
{

	if (args[1] == NULL)
	{
		perror("cd");
	}
	else if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}

	return (1);
}


/**
 * call_help - function description
 *
 * Return: void
 */


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


int call_help(char *cmd)
{

	char *file;
	int fd, r;
	char *s;

	if (cmd == NULL)
	{
		s = "help: no builtin entered.\n";
		r = _strlen(s);
		r = write(1, s, r);
		return (0);
	}

	if (!_strcmp(cmd, "cd"))
	{
		file = "help_cd";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "history"))
	{
		file = "help_hist";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "help"))
	{
		file = "help_hel";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "alias"))
	{
		file = "help_al";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "unset"))
	{
		file = "help_unset";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "unalias"))
	{
		file = "help_unal";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "env"))
	{
		file = "help_env";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "unsetenv"))
	{
		file = "help_unenv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "setenv"))
	{
		file = "help_setenv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else
	{
		s = "help: no help topics match.\n";
		r = _strlen(s);
		r = write(1, s, r);
		return (0);
	}
}
