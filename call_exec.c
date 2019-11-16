#include "shell.h"

int exec_cmd(char **str, char **env)
{
	pid_t pid, wpid;
	int id = 0;

	pid = fork();
	if (pid == 0)
	{
		printf("STR: %s\n", *str);
		id = execve(str[0], str, env);
		if(id == -1)
			perror("hsh");
	}
	else if (pid < 0)
		printf("Error\n");
	else
		
		do
		{
			wpid = waitpid(pid, &id, WUNTRACED);

		}
		while(!WIFSIGNALED(id) && !WIFEXITED(id));
	
	return (1);		
}
