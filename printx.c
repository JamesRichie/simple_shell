#include "shell.h"

/**
 * printx - Prints inputs
 * @c: input
 */
void printx(const char *c)
{
	write(STDOUT_FILENO, c, strlen(c));
}
