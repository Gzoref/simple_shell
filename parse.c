#include "shell.h"

char **parse_line(char *line)
{
	int buffer_size = BUFFERSIZE;
	int location = 0;
	char **tokens;
	char *token;

	tokens = malloc(sizeof(char*) * buffer_size);

	if (!tokens)
	{
		perror("hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMINATOR);

	while (token != NULL)
	{
		tokens[location] = token;
		location++;
	}

	if (location >= buffer_size)
	{
		buffer_size += BUFFERSIZE;
		tokens = realloc(tokens, buffer_size * sizeof(char*));

		if (!tokens) {
			{
				perror("hsh: allocation error\n");
			exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMINATOR);
	}
	tokens[location] = NULL;

	return (tokens);
}
