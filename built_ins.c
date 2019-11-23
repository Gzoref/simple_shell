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
		perror("hsh");
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

void call_cd(char **args)
{

	int current = 0, index = 0;
	char current_directory[BUFFERSIZE];


	if (args[1] == NULL) /*  Only type cd with no args after  */
	{
		chdir(getenv("HOME"));
	}
	else if (_strcmp(args[1], "-")  == 0) /*  If first arg after cd is -  */
	{
		if (getenv("OLDPWD") == NULL)
		{
			chdir(".");
		}
		else
		{
			chdir(getenv("OLDPWD"));
			getcwd(current_directory, sizeof(current));

			while (current_directory[index] != '\0')
			{
				index++;
				current++;
			}
			current_directory[index] = '\n';
			write(1, current_directory, current + 1);
		}
	}
	else
		chdir(args[1]);
}
