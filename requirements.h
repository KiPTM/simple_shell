#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H
#define MAX_INPUT_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void read_command(char cmd[]);
void type_prompt(void);
void execute_command(char cmd[]);

#endif
