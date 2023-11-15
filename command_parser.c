#include "command_parser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

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

/* extern char **environ; */ 

int parse_command_with_args(const char *cmd, char **command, char ***args)
{
	/**
	 * Implementing the parse_with_args function
	 * splitting the command string by space to separate command and arguements
	 */	
	char *token;
	int num_tokens = 0;
	char *cmd_copy = strdup(cmd);
	char *temp = cmd_copy;
	token = strtok(cmd_copy, " \t\n"); /* Separate by space, tab, or newline */
	*command = strdup(token); /* Set the command */
	*args = malloc(sizeof(char *) * 10); /* Allocate memory for arguments */
	while (token != NULL)
	{
		(*args)[num_tokens] = strdup(token); /* Store arguments */
		num_tokens++;
		token = strtok(NULL, " \t\n");
	}
	(*args)[num_tokens] = NULL; /* Terminate the argument array */
	free(temp); /* Free temporary memory */
	
	return (num_tokens);
}

void execute_command(const char *cmd){
    pid_t child_pid;
    int status;
    char *command = NULL;
    char **args = NULL;
    int i; /* loop counter declaration  here */

    int num_args = parse_command_with_args(cmd, &command, &args);
    printf("Command: %s\n", command); /* Debug statement */

    if (num_args >= 0) {
        printf("Arguments: ");
        for (i = 0; i < num_args; i++) {
            printf("%s ", args[i]); /* Debug statement */
        }
        printf("\n");

        /* Execute command */
        if (command != NULL && command[0] != '\0') {
            child_pid = fork();
            if (child_pid == -1) {
                perror("Fork error");
                exit(EXIT_FAILURE);
            }

            if (child_pid == 0) {
                /* Get the absolute path for the command if available*/
                char command_path[256];
                if (realpath(command, command_path) == NULL) {
                    fprintf(stderr, "Command '%s' not found\n", command);
                    exit(EXIT_FAILURE);
                }

                if (execve(command_path, args, environ) == -1) {
                    perror("Execution error");
                    exit(EXIT_FAILURE);
                }
            } else {
                waitpid(child_pid, &status, 0);
            }
        } else {
            printf("Empty command.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    free(command);
    free_args(args);
}



int execute_command_with_args(const char *command, char **args) {
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1) {
		perror("Fork error");
		return 1;
	}

	if (child_pid == 0) {
		/* child process */
		if (execve(command, args, NULL) == -1) {
			perror("Error");
			return 1;
		}
	}else{
		/*Parent process*/
		waitpid(child_pid, &status, 0);
	}

	return 0;
}
