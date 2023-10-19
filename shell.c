#include "shell.h"

/**
 * main - execute the simple shell
 */
int main(void)
{
	char func_name[] = "My function";
	char var_name[] = "My Variable Name";
	char id1[] = "123 identifier";
	char id2[] = "good identifier";
	char input[150];

	while(1)
	{
		_prompt();
		execute(input);
		read_cmd(input, sizeof(input));
	}
	if (snake_case(func_name))
	{
		printx("Function name follows snake_case.\n");
	}
	else
		printx("Function name does not follow snake_case.\n");

	if (snake_case(var_name))
	{
		printx("Variable name follows snake_case.\n");
	}
	else
		printx("Variable name does not follow snake_case.\n");

	if (valid_id(id1))
	{
		printf("Identifier 1 is a valid identifier.\n");
	}
	else
		printf("Identifier 1 is not a valid identifier.\n");

	if (valid_id(id2))
	{
		printf("Identifier 2 is a valid identifier.\n");
	}
	else
		printf("Identifier 2 is not a valid identifier.\n");

	return (0);
}

