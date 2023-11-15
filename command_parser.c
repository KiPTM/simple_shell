#include "command_parser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * free_args - frees the memory used by an array of strings.
 * @args: The array of strings to be free.
 */
void free_args(char **args) {
	int i;
	for (i = 0; args[i] != NULL; i++) {
		free(args[i]);
	}
	free(args);
}

extern char **environ;

void execute_command(char **cmd, char *strName)
{
	pid_t child_pid;
	int status;
	char *cmd_path;
	(void)cmd;

	if (cmd != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(strName);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			cmd_path = allocate_path(cmd[0]);
			if (execve(cmd[0], cmd, environ) == -1)
			{
				perror(strName);
				exit(EXIT_FAILURE);
			}
		}
		else {
			waitpid(child_pid, &status, 0);
		}
	}
}
