#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <stdio.h>
#include <stdlib.h>

int  parse_command_with_args(const char *cmd, char **command, char ***args);
void execute_command(char **args, char *strName);
char *allocate_path(const char *cmd);


#endif
