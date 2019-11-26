#include "shell.h"

/**
 * main - Main funtion, gateway to shell commands & prompt loop
 *
 * @argc: Argument count
 *
 * @argv: Vectorized args
 *
 * Return: 0 on success
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char *buffer = NULL;
	char **args;
	int value = 1;
	int loop_count = 0;

	while (value)
	{
		signal(SIGINT, ctrl_c_handler); /* Stop ctrl ^C from exiting */
		head = argv[0];
		head = _strcat(argv[0], ":");

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2); /* Write $ for shell */

		buffer = read_line(); /* Reads from command line */
		args = parse_line(buffer); /* Use strtok to put args in array */
		value = function_filter(args, environ); /* Tell if builtin */
		free(args);
		free(buffer);
		loop_count++;
	}
	return (0);
}


/**
 *  ctrl_c_handler - Handles control C
 *
 * @sig_num: Integer
 *
 * Return: void
 */

void ctrl_c_handler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, ctrl_c_handler);
	write(STDOUT_FILENO, "\n$ ", 3);

}
