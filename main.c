#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "command_parser.h"

int main(void) {
    char input[1024];
    char *cmd;
    char **args = NULL;


    while (1) {
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strlen(input) - 1] = '\0';

        cmd = input;

        parse_command_with_args(cmd, &cmd, &args);

if (args != NULL) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        /* Child process */
        if (execve(cmd, args, NULL) == -1) {
            perror("execve");
            _exit(1);
        }
    } else {
        /* Parent process */
        wait(NULL);
    }
}


        if (args != NULL) {
            int i;
            for (i = 0; args[i] != NULL; i++) {
                free(args[i]);
            }
            free(args);
        }
    }

    return 0;
}

