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


int snake_case(const char *str);
int valid_id(const char *str);


#endif
