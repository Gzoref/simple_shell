#include "shell.h"
/**
 * call_unsetenv - Unsets enviorments variabls
 * @env: Enviorment variables
 * @str: User input
 * Return: Always 1
 */

int call_unsetenv(char **env, char **str)
{
	int i = 0, id = 0;

	i = find_env_var(env, str[1]);
	printf("%s\n", env[i]);

	id = 0;
	while (env[i] != NULL)
	{
		env[i] = env[i + 1];
		i++;
	}

	return (1);

}
