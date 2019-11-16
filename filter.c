#include "shell.h"

int function_filter(char **commands)
{
	cmd_fo format[] = {
		{"exit", &call_exit},
		{NULL, NULL}	
	};
	
	int i = 0;
	
	for (i = 0; format[i].id != NULL; i++)
		if (*commands == format[i].id)
			return (format[i].f);

	return (exec_cmd(commands));
}
