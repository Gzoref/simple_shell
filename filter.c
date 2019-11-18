#include "shell.h"


/**
 * function_filter - Filters built-ins & sends them to appropriate function
 *
 * @commands: Double pointer from command ine
 *
 * Return: exec_cmd function
 */


int function_filter(char **commands)
{
	int i = 0;

	char *builtin[5];

	builtin[0] = "exit";
	builtin[1] = "cd";
	builtin[2] = "help";
	builtin[3] = NULL;

	while (builtin[i] != NULL)
	{
		if (_strcmp(builtin[i], commands[0]) == 0)
		{
			switch (i)
			{
			case 0:
				call_exit();
				break;
			}
		}
		else
		{
			i++;
		}
	}
	return (exec_cmd(commands, __environ));
}
