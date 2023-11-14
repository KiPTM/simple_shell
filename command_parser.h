#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <stdio.h>
#include <stdlib.h>

int  parse_command_with_args(const char *cmd, char **command, char ***args);
int execute_command_with_args(const char *command, char **args);


#endif
