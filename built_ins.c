#include "shell.h"

int call_exit (char **name)
{
	printf("Went through exit %s", *name);
	return (0);
}
