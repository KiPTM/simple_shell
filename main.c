#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "command_parser.h"
#include "requirements.h"

/**
 * main - Entry point of the program
 *
 * Description: This function serves as the entry point
 *              for the program, executing the main logic.
 * Return: Always 0 on success.
 */

int main(void)
{
	char input[1024];

	while (1)
	{
		printf("$ ");
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		break;
	}
	input[strlen(input) - 1] = '\0';
	execute_command(input);
	}

	return (0);
}
