#include "main.h"

/**
 * display_env - Output the shell local environment details
 * @av: Array of arguments values
 */

void display_env(char *av[])
{
	char **env = environ;
	int i = 0;

	if (strcmp(av[0], "env") == 0)
	{
		while (i  < 12)
		{
			if (*env)
				puts(env[i]);
			env++;
			i++;
		}

	} else if (strcmp(av[0], "exit") == 0)
	{
		shell_exit(av);
	}
}
