#include "shell.h"

/**
 * function_filter - Filters built-ins & sends them to appropriate function
 *
 * @commands: Double pointer from command line
 *
 * @env: Environment variable
 *
 * Return: exec_cmd function
 */

int function_filter(char **commands, char **env)
{
	int option = 0;

	char *builtin[5];

	builtin[0] = "exit";
	builtin[1] = "cd";
	builtin[2] = "help";
	builtin[3] = "env";
	builtin[4] = NULL;

	if (commands[0] == NULL)
		return(1);

	while (builtin[option] != NULL)
	{
		if (_strcmp(builtin[option], commands[0]) == 0)
		{
			break;
		}
		option++;
	}

	switch (option)
	{
	case 0:
		call_exit(*commands);
		break;
	case 1:
		call_cd(commands);
		break;
	default:
		return (exec_cmd(commands, env));
	}
	return (option);
}
