#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

void execute_command(char **args, char *strName);
char *allocate_path(const char *cmd);
void self_builtin(char **cmd);
void my_exit(int status);
void print_env();


#endif
