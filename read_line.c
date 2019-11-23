#include "shell.h"

char * read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int i = 0;
	i = getline(&line, &bufsize, stdin);
	if (i == EOF)
	{
		write(1, "\n", 1);
		exit(1);
	}
	return (line);
}
