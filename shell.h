#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


/* Function */
void printx(const char *c);
void _prompt(void);
void execute(const char *input);
void read_cmd(char *input, size_t size);
int _getline(char *input, int size);
int parse_cmd(char *cmd);

int snake_case(const char *str);
int valid_id(const char *str);

int _strcmp(char *first_str, char *second_str);

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define MAX_INPUT_SIZE 1000

#define INT_COMMAND 2
#define EXT_COMMAND 1
#define PATH_COMMAND 3
#define INV_COMMAND -1

#endif
