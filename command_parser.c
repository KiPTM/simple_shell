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

void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}

extern char **environ;

/**
 * execute_command - Execute command in a child process using fork and execve
 * @cmd: Command arguments
 * @strName: Command name
 * @args - arguements
 * Description: This function executes a command along with its arguments
   using execve system call.
 * Return: No return value
 */

void execute_command(char **cmd, char *strName)
{
	pid_t child_pid;
	int status;
	char **args = NULL;
	(void)cmd;

	if (cmd != NULL)
	{
                child_pid = fork();
                if (child_pid == -1) {
                        perror("Fork error");
                        exit(EXIT_FAILURE);
                }

                if (child_pid == 0) {
                        if (execve(cmd[0], cmd, environ) == -1) {
                                perror("Execution error");
                                exit(EXIT_FAILURE);
                        }
                }
                else {
                        waitpid(child_pid, &status, 0);
                }

                free_args(args);
		/*free_args(cmd);*/
	}
	else
	{
		printf("Empty command.\n");
	}

	/*free(command);*/
}

/**
 * execute_command_with_args - executes cmd along with args using execve
 * @args: arguements
 * return: 0
 * Description: always return 0
 */

int execute_command_with_args(const char *command, char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		return (1);
	}

	if (child_pid == 0)
	{
		/* child process */
		if (execve(command, args, NULL) == -1)
		{
			perror("Error");
			return (1);
		}
	}
	else
	{
		/*Parent process*/
		waitpid(child_pid, &status, 0);
	}

	return (0);
}
