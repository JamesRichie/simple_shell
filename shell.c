#include "shell.h"

/**
 * main - execute the simple shell
 */
int main(void)
{
	char input[150];

	while(1)
	{
		_prompt();
		execute(input);
		read_cmd(input, sizeof(input));
	}
	return (0);
}

