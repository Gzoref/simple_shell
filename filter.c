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

	char *builtin[5] = {"exit", "cd", "env", "help", NULL};

	if (commands[0] == NULL) /* If no args at all, continue */
	{
		return (1);
	}

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
	case 0: /* Exit */
		if (commands[1] == NULL) /* Only exit is typed */
		{
			call_exit(*commands);
		}
		else
		{
			call_exit_status(commands); /* Is  2nd arg after exit */
		}
		break;
	case 1:
		call_cd(commands); /* cd is typed */
		[<8;94;28m		break;
	case 2:
		call_env(env); /* env is typed */
		break;
	default:
		return (exec_cmd(commands, env));
	}
	return (option);
}
