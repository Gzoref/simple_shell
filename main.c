#include "shell.h"

/**
 * main - Main funtion, gateway to shell commands
 *
 * @argc: Integer
 *
 * @argv: Double pointer arguments
 *
 * @env: Double pointer environment
 *
 * Return: 1 on success
 */


int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char **args;
	int value = 0;

	do {
		signal(SIGINT, ctrl_c_handler);
		write(STDOUT_FILENO, "$ ", 2);
		buffer = read_line();
		args = parse_line(buffer);
		value = function_filter(args, env);
		free(buffer);
		free(args);
	} while (value > 0);

	return (1);
}


/**
 *  ctrl_c_handler - Handles control C
 *
 * @sig_num: Integer
 *
 *  Return: void
 */

void ctrl_c_handler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, ctrl_c_handler);
	write(STDOUT_FILENO, "\n$ ", 3);

}
