#include "shell.h"

int function_filter(char **commands, char **env)
{
	cmd_fo format[] = {
		{"exit", &call_exit},
		{NULL, NULL}	
	};
	
	int i = 0;
	
	for (i = 0; format[i].id != NULL; i++)
		if (commands[0] == format[i].id)
			return ((format[i].f)(commands));

	return (exec_cmd(commands, env));
}
