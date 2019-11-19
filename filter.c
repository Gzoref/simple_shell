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
		printf("Got here 1\n");
		if (_strcmp(builtin[i], commands[0]) == 0)
		{
			printf("Got here 2\n");
			switch (i)
			{
			case 0:
				printf("Got here 3\n");
				call_exit();
				break;
			case 1:
				call_cd();
			default:
				return (exec_cmd(commands, __environ));
			}
		}
		i++;
	}
	return (1);
}
