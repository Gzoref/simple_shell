#include "shell.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int find_path(char **enviorment);

int exec_cmd(char **str, char **env)
{
	
	pid_t pid, wpid;
	int id = 0, i = 0, c = 5, count = 0;
	char *newstr = malloc(sizeof(char) * BUFFERSIZE), *path = malloc(sizeof(char) * BUFFERSIZE);
	char *new2 = malloc(sizeof(char) * BUFFERSIZE);
	char *newp = NULL;
	
	memset(new2, '\0', BUFFERSIZE);
	
	i = find_path(env);
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



int find_path(char **env)
{
	char *args;
	char *path = malloc(sizeof(char) * BUFFERSIZE);
	int id = 0;
	int i = 0;
	
	while (*env)
	{
		
		strcpy(path, env[i]);

		args = strtok(path, "=");
		if ((id = strcmp(args, "PATH")) == 0)
		{
			return(i);
		}
		strtok(NULL, "\0");
		i++;
	}
	return (0);
}
