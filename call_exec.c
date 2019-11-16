#include "shell.h"

int exec_cmd(char **str)
{
	pid_t pid, wpid;
	int id = 0;

	pid = fork();
	if (pid == 0)
		id = execve(str[0], &str[0], 0);
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
