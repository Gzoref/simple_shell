#include "shell.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int find_env_var(char **enviorment, char *str);
int check_input(char **str, char **env);

int exec_cmd(char **str, char **env)
{
	
	pid_t pid, wpid;
	int id = 0, i = 0, c = 5, count = 0, flag = 0;
	char *newstr = malloc(sizeof(char) * BUFFERSIZE), *path = malloc(sizeof(char) * BUFFERSIZE);
	char *new2 = malloc(sizeof(char) * BUFFERSIZE);
	char *newp = NULL;
	
	memset(new2, '\0', BUFFERSIZE);

	if ((flag = check_input(str, env)) == 1)
		return(1);

	i = find_env_var(env, "PATH");
	path = strcpy(path, env[i]);
	count = strlen(path - 5);
	while(id < count - 1)
	{
		new2[id] = path[c];
		id++;
		c++;
	}
	
	newp = _strcat("/", str[0]);
	pid = fork();
	if (pid == 0)
	{
		strcpy(new2, env[i]);
		path = strtok(new2, ":");
		while (path)	
		{	
			newstr = _strcat(path, newp);
			if ((id = access(newstr, X_OK)) == 0)
			{
				id = execve(newstr, str, env);
				if(id == -1)
				{
					perror("hsh");
				}
			}
			path = strtok(NULL, ":");
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		perror("hsh");
	else
		
		do
		{
			wpid = waitpid(pid, &id, WUNTRACED);

		}
		while(!WIFSIGNALED(id) && !WIFEXITED(id));

	return (1);
}



char *_getenv(char **env, char *str)
{
	char *args, *copy = malloc(BUFFERSIZE);
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int id = 0, len = 0, len2 = 0;
	int i = 0;

	add_node(&head, path);
	add_node(&head, copy);
	add_node(&head, args);

	while (*env)
	{
			
		path = _strdup(env[i]);

		args = strtok(path, "=");
		if (args != NULL && (id = _strcmp(args, str)) == 0)
		{
			path = _strdup(env[i]);

			while(args[++len])
				;	
			len2 = len + 1;
			id = _strlen(path) - len2;
			i = 0;
			while(i < id - 1)
			{
				copy[i] = path[len2];
				i++;
				len2++;
			}
			return(copy);
		}
		strtok(NULL, "\0");
		i++;
	}
	return(NULL);
}

int find_env_var(char **env, char *str)
{
	char *args;
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int id = 0;
	int i = 0;
	while (*env)
	{
			
		path = _strdup(env[i]);

		args = strtok(path, "=");
		if (args != NULL && (id = _strcmp(args, str)) == 0)
		{
			free(args);
			free(path);
			return(i);
		}
		strtok(NULL, "\0");
		i++;
	}
	free(args);
	free(path);
	return(0);
}

int check_input(char **str, char **env)
{
	pid_t pid, wpid;
	int id = 0, i = 0;
	char *sep = "/";
	char *copy = _strdup(str[0]);

	if ((i = access(str[0], R_OK | X_OK)) == 0)
	{
		
		pid = fork();
		if (pid == 0)
		{
			id = execve(str[0], str, env);
			if(id == -1)
			{
				perror("hsh");
			}
			exit(EXIT_SUCCESS);
		}
		else if (pid < 0)
			perror("hsh");
		else
		
			do
			{
				wpid = waitpid(pid, &id, WUNTRACED);

			}
			while(!WIFSIGNALED(id) && !WIFEXITED(id));
		free(copy);
		return (1);
	}
	else if (copy != NULL)
	{
		for (i = 0; copy[i] != '\0'; i++)
			if(copy[i] == sep[0])
			{
				errno = ENOENT;
				perror("hsh");
				free(copy);
				return(1);
			}
	}
	free(copy);
	return (0);		
}
