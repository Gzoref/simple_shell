#include "shell.h"

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
