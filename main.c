#include "shell.h"

/**
 *  main - Main funtion, gateway to shell commands
 *
 *  @argc: Integer
 *
 *  @argv: Double pointer
 *
 *  Return 1 on success
 */



int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char **args;
	int value = 0;

	while(1)
	{
		signal(SIGINT, cntl_c_handler);
		write(STDOUT_FILENO, "$ ", 2);
		buffer = read_line();
		args = parse_line(buffer);
		value = function_filter(args, env);
		free(buffer);
		free(args);
	}
	return (0);
}


/**
 *  cntl_c_handler - Handles control C
 *
 *  Return: void
 */

void cntl_c_handler()
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
