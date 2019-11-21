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
	fflush(stdout);
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
