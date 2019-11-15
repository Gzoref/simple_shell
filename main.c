#include "shell.h"


int main(int argc, char **argv, char **envs)
{
	char *commandLine = NULL, *token;
	size_t readLength = 0;
	ssize_t characters;
	pid_t pid;
	int index = 0;

	do
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	while((commandLine = read_line(commandLine)));
	token = strtok(commandLine, " ");
	pid = fork();
}
