#include "shell.h"

/**
 * read_cmd - Processses the users input
 * @input: The users input
 * @size: Size of input
 *
 */
void read_cmd(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printx("\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			printx("Error ehile processing input");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
