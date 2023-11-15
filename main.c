#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "command_parser.h"

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
        	write(1, "$ ", 2);
        	if (fgets(input, sizeof(input), stdin) == NULL)
            		break;


        	input[strlen(input) - 1] = '\0';

        	cmd = input;

        	args[0] = strtok(cmd, delim);
        	for (i = 0; args[i] != NULL; i++)
                	args[++i] = strtok(NULL, delim);

        	execute_command(args, programName);
	} 
    return 0;
}
