#include "shell.h"

char * read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int i = 0;
	i = getline(&line, &bufsize, stdin);
	if (i == -1)
		call_exit("\n");
	return (line);
}
