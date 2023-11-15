#include "command_parser.h"
#include "requirements.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * read_command - Reads input command from standard input
 * @cmd: Buffer to store the input command
 *
 * Description: This function reads a command from the standard input
 *              and stores it in the provided buffer 'cmd'.
 */

void read_command(char cmd[])
{
	if (fgets(cmd, MAX_INPUT_SIZE, stdin) == NULL)
	{
		/* Prints a new line and exits on EOF (ctrl+D) */
		printf("\n");
		exit(0);
	}
	/* Removes the trailing newline character */
	cmd[strcspn(cmd, "\n")] = '0';
}

/**
 * type_prompt - Prints the command prompt
 *
 * Description: This function prints the command prompt '$ '.
 */
void type_prompt(void)
{
	printf("$ ");
}
