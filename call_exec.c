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
	char *newstr = malloc(sizeof(char) * BUFFERSIZE);
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	char *new2 = malloc(sizeof(char) * BUFFERSIZE);
	char *newp = NULL;
	memset(new2, '\0', BUFFERSIZE);
	if ((flag = check_input(str, env)) == 1)
		return(1);
	if (newstr == NULL || path == NULL || new2 == NULL)
		call_exit(NULL);

	i = find_env_var(env, "PATH");
	path = _strcpy(path, env[i]); /* changed to be our own function */
	count = _strlen(path - 5); /* changed to be our own function */
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
		_strcpy(new2, env[i]);
		path = strtok(new2, ":");
		while (path)	
		{	
			newstr = _strcat(path, newp);
			if ((access(newstr, X_OK)) == 0)
			{
				id = execve(newstr, str, env);
				if(id == -1)
				{
					perror(head);
				}
			}
			free(newstr);
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
			if (wpid == -1)
				perror(head);

		}
		while(!WIFSIGNALED(id) && !WIFEXITED(id));
	free(newp);
	free(newstr);
	free(path);
	free(new2);
	return (1);
}



char *_getenv(char **env, char *str)
{
	char *args = NULL, *copy = malloc(BUFFERSIZE);
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int id = 0, len = 0, len2 = 0;
	int i = 0;
	
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
			free(path);
			return(copy);
		}
		strtok(NULL, "\0");
		i++;
	}
	free(copy);
	free(path);
	return(NULL);
}

int find_env_var(char **env, char *str)
{
	char *args = NULL;
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int id = 0;
	int i = 0;
	
	while (*env)
	{
			
		path = _strdup(env[i]);
		args = strtok(path, "=");

		if (args != NULL && (id = _strcmp(args, str)) == 0)
		{
			free(path);
			return(i);
		}
		free(path);
		args = strtok(NULL, "\0");
		i++;
	}
	return(0);
}

int check_input(char **str, char **env)
{
	pid_t pid, wpid;
	int id = 0, i = 0;
	char *sep = "/";
	char *copy = NULL;
	copy = _strdup(str[0]);
	
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
				if (wpid == -1)
					perror(head);

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
