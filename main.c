#include "shell.h"

/**
 * main - Start the execution
 * @argc: Total number of args
 * @argv: Array of args
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
	char input[1024];
	char *cmd;
	char *args[100] = {NULL, NULL};
	int i;
	char delim[] = " \t\n\b\r", *programName = argv[0];
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			return (0);
		}

		input[strlen(input) - 1] = '\0';

		cmd = input;

		args[0] = strtok(cmd, delim);
		for (i = 0; args[i] != NULL; i++)
			args[++i] = strtok(NULL, delim);

		self_builtin(args);
		execute_command(args, programName);
	}
	return (0);
}
