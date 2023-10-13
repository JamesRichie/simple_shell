#include "shell.h"
int _getchar(void);
/**
 * _getline - Reads entire line of input
 * @input: The input by user
 * @size: number of input 
 *
 */
int _getline(char *input, int size)
{
	int x = 0, y;

	while (x < size - 1 && (y = getchar()) != '\n' && x != EOF)
	{
		input[x++] = y;
	}
	input[x] = '\0';
	return (x);
}

/**
 * _getchar - Reads single characters
 *
 */
int _getchar(void)
{
	int c;
	c = read(0, &c, 1);
	return (c);
}
