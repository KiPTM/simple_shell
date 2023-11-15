#include "main.h"

/**
 * shell_exit - Wait for a child process to terminate and handle exit status.
 * @av: The argument vector containing the program name and its arguments.
 *
 * Description: Waits for the child process with the given PID to terminate
 *              and retrieves its exit status. If the child process has exited
 *              successfully (with exit code 0) and the program name in the
 *              argument vector is NULL, it will also call exit(0) to terminate
 *              the parent process.
 */

void shell_exit(char **av)
{
	int s;

	if (av[1])
	{
		s = atoi(av[1]);
		if (s >= 0)
			exit(s);
		perror("Exit");
	}
	exit(0);
}
