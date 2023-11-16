#include "shell.h"

/**
 * self_builtin - Output the shell local environment details
 * @cmd: Array of arguments values
 */
void self_builtin(char **cmd)
{
	if (strcmp(cmd[0], "exit") == 0)
		my_exit(0);
	else if (strcmp(cmd[0], "env") == 0)
		print_env();

}

/**
 * my_exit - Terminate the child process
 * @status: status value for exiting
 */
void my_exit(int status)
{
	exit(status);
}

/**
 * print_env - Output the short detail of the environment
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}
