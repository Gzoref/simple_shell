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
	exit(EXIT_SUCCESS);
	free(args);

	return (1);
}

int call_exit_status(char **args)
{
	int status;

	status = _exit_atoi(args[1]);

        if (status == -1)
	{
		perror("hsh: ");
		return (-1);
	}
	else
	{
		exit(status);
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
	char *targetDir = NULL, *home = NULL;
	char prevDir[BUFFERSIZE];

	printf("%s\n", home);
	home = _getenv(environ, "HOME");
	printf("%s\n", home);

	if (args[1])
	{
		/* For cd ~ go home */
		if (_strcmp(args[1], "~"))
		{
			targetDir = home;
			printf("%s\n", targetDir);
		}
		/* cd - goes to previos directory */
		else if (_strcmp(args[1],"-"))
		{
			targetDir = _getenv(environ, "OLDPWD");
			printf("%s\n", targetDir);
		}
		else
		{
			targetDir = args[1];
			printf("%s\n", targetDir);
		}
	}
	else
	{
		targetDir = home;
		printf("%s\n", targetDir);
	}

	if (targetDir == home)
	{
		chdir(targetDir);
		printf("%s\n", targetDir);
	}
	/* F_OK tests if there */
	/* R_OK grants read permissions */
	else if (access(targetDir, F_OK | R_OK) == 0)
	{
		chdir(targetDir);
	}
	else
	{
			perror("hsh");
	}
	setenv("OLDPWD", _getenv(environ, "PWD"), 1);
	setenv("PWD", getcwd(prevDir, sizeof(prevDir)), 1);

	return (0);
}
