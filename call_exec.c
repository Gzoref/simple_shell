#include "shell.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int find_env_var(char **enviorment, char *str);
int check_input(char **str, char **env);
char *_getenv(char **env, char *str);
/**
 * exec_cmd - Takes in a command to execute
 * @env: The enviorment
 * @str: The vectorized array of user input
 * Return: 1 or 0 depenging on what happens
 */
int exec_cmd(char **str, char **env)
{
	pid_t pid, wpid;
	int id = 0;
	char *newstr = malloc(sizeof(char) * BUFFERSIZE);
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	char *new2 = malloc(sizeof(char) * BUFFERSIZE);
	char *newp = NULL;

	if ((check_input(str, env)) == 1)
		return (1);
	if (newstr == NULL || path == NULL || new2 == NULL)
		call_exit(NULL);

	new2 = _getenv(env, "PATH");
	newp = _strcat("/", str[0]);
	pid = fork();
	if (pid == 0)
	{
		path = strtok(new2, ":");
		while (path)
		{
			newstr = _strcat(path, newp);
			if ((access(newstr, X_OK)) == 0)
			{
				free(newp);
				id = execve(newstr, str, env);
				if (id == -1)
					perror(head);
			}
			free(newstr);
			path = strtok(NULL, ":");
		}
		errno = ENOENT;
		perror(head);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		perror("hsh");
	else
		do {
			wpid = waitpid(pid, &id, WUNTRACED);
			if (wpid == -1)
				perror(head);

		} while (!WIFSIGNALED(id) && !WIFEXITED(id));
	free(newp);
	free(newstr);
	free(path);
	free(new2);
	return (1);
}

/**
 * _getenv - Finds the enviroment variable
 * @env: The enviorment
 * @str: Variable to find
 * Return: 1 or 0 depenging on what happens
 */
char *_getenv(char **env, char *str)
{
	char *args = NULL, *copy = malloc(sizeof(char *) * BUFFERSIZE);
	char *path = malloc(sizeof(char *) * BUFFERSIZE);
	int id = 0, len = 0, len2 = 0;
	int i = 0;

	while (*env)
	{
		path = _strdup(env[i]);

		args = strtok(path, "=");
		if (args != NULL && (_strcmp(args, str)) == 0)
		{
			path = _strdup(env[i]);

			while (args[++len])
				;
			len2 = len + 1;
			id = _strlen(path) - len2;
			i = 0;
			while (i < id)
			{
				copy[i] = path[len2];
				i++;
				len2++;
			}
			free(path);
			return (copy);
		}
		free(path);
		i++;
	}
	free(copy);
	free(path);
	return (NULL);
}
/**
 * find_env_var - Finds the enviroment variable
 * @env: The enviorment
 * @str: Variable to find
 * Return: The index of the wanted variable
 */
int find_env_var(char **env, char *str)
{
	char *args = NULL;
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int i = 0;

	while (*env)
	{
		path = _strdup(env[i]);
		args = strtok(path, "=");

		if (args != NULL && (_strcmp(args, str)) == 0)
		{
			free(path);
			return (i);
		}
		free(path);
		i++;
	}
	return (0);
}

/**
 * check_input - Checks if the input is already a path
 * @env: The enviorment
 * @str: Vectorized array of input
 * Return: 1 or 0 depenging on what happens
 */
int check_input(char **str, char **env)
{
	pid_t pid, wpid;
	int id = 0, i = 0;
	char *sep = "/";
	char *copy = NULL;

	copy = _strdup(str[0]);
	if ((access(str[0], R_OK | X_OK)) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			id = execve(str[0], str, env);
			if (id == -1)
			{
				perror(head);
			}
			exit(EXIT_SUCCESS);
		}
		else if (pid < 0)
			perror(head);
		else
			do {
				wpid = waitpid(pid, &id, WUNTRACED);
				if (wpid == -1)
					perror(head);
			} while (!WIFSIGNALED(id) && !WIFEXITED(id));
		free(copy);
		return (1);
	}
	else if (copy != NULL)
	{
		for (i = 0; copy[i] != '\0'; i++)
			if (copy[i] == sep[0])
			{
				errno = ENOENT;
				perror(head);
				free(copy);
				return (1);
			}
	}
	free(copy);
	return (0);
}
