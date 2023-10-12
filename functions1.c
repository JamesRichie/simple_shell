#include "shell.h"
/**
 * execute - executes a command based on it's type
 * @tokenized_cmd: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @cmd_type: type of the command
 *
 * Return: void
 */
void execute(char **tokenized_cmd, int cmd_type)
{
	void (*funct)(char **command);

	if (cmd_type == EXT_COMMAND)
	{
		if (execve(tokenized_cmd[0], tokenized_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (cmd_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_cmd[0]), tokenized_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (cmd_type == INT_COMMAND)
	{
		funct = get_func(tokenized_cmd[0]);
		funct(tokenized_cmd);
	}
	if (cmd_type == INVALID_COMMAND)
	{
		printx(shell_name, STDERR_FILENO);
		printx(": 1: ", STDERR_FILENO);
		printx(tokenized_cmd[0], STDERR_FILENO);
		printx(": not found here\n", STDERR_FILENO);
		status = 125;
	}
}
