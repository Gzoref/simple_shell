#include "shell.h"


int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char **args;
	int value = 0;
	
	do
	{
		write(STDOUT_FILENO, "$ ", 2);
		buffer = read_line();
		args = parse_line(buffer);
		value = function_filter(args, env);
		free(buffer);
		free(args);
	}
	while(value > 0);
}
