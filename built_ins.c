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



int _exit_atoi(char *str)
{
	int result = 0, index = 0, int_max = 2147483647;

	/* Is negative */
	if (str[index] == '-')
	{
		return(-1);
	}

	for (index = 0; str[index] != '\0'; index++)
	{
		if (_isdigit(str[index]))
		{
			result = result * 10 + str[index] - '0';
		}
		else
		{
			return (-1);
		}
	}

	if (result > int_max)
	{
		return (-1);
	}

	else
		return (result);
}


int _isdigit(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}
