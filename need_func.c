#include "shell.h"

/**
 *_strcmp - compare two strings
 *@first_str: first string to be compared
 *@second_str: second string to be compared
 *
 * Return: difference of the two strings
 */

int _strcmp(char *first_str, char *second_str)
{
	int x = 0;

	while (first_str[x] != '\0')
	{
		if (first_str[x] != second_str[x])
			break;
		x++;
	}
	return (first_str[x] - second_str[x]);
}
