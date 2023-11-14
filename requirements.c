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
