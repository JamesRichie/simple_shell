#include "shell.h"

/**
 * initializer - starts executing everything
 * @curr_cmd: checks current token
 * @type_cmd: parse token
 *
 * Return: void function
 */

void initializer(char **curr_cmd, int type_cmd)
{
	pid_t PID;

	if (type_cmd == EXT_COMMAND || type_cmd == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(curr_cmd, type_cmd);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(curr_cmd, type_cmd);
}
