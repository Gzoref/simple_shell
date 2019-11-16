#include "local.h"
#include <unistd.h>

int call_exec(char **str)
{
	pid_t pid, wpid;
	int id;

	pid = fork();
	if (pid == 0)
		id = execve(str[0], &str[0], 0);
	else if (pid > 0)
		printf("Error");
	else
		while(!WIFISIGNALED(status) && !WIFIEXITED(status))
		{
			wpid = wait(pid, &status, WUNTRACED);
		}
	return 1;
		
}
