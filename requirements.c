#include "command_parser.c"
#include "requirements.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void read_command(char cmd[]) {
	if (fgets(cmd, MAX_INPUT_SIZE, stdin) == NULL) {
		/* Prints a new line and exits on EOF (ctrl+D) */
		printf("\n");
		exit(0);
	}
	/* Removes the trailing newline character */
	cmd[strcspn(cmd, "\n")] = '0';
}

void type_prompt(void) {
	printf("$ ");
}

void execute_command(char cmd[]) {
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1) {
		perror("Fork error");
		exit(1);
	}

	if (child_pid == 0) {
		/*child process*/
		char *args[2];
		args[0] = cmd;
		args[1] = NULL;
		if (execve(cmd, args, NULL) == -1){
			perror("Error");
			exit(1); /*Exit the child process with an error */
		}
	} else {
		/*Parent process*/
		waitpid(child_pid, &status, 0);
	}
}
