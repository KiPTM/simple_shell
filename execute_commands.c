#include "shell.h"

/**
 * execute_command - Runs the command entered
 * @cmd: The array of commands strings
 * @strName: The name of the program
 */
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
			if (!cmd_path)
			{
				perror(strName);
				exit(0);
			}

			if (execve(cmd_path, cmd, NULL) == -1)
			{
				perror(strName);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
}
