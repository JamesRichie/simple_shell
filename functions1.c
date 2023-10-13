#include "shell.h"
/**
 * execute - executes a command 
 * @input: Imnput by user
 *
 * Return: void
 */
void execute(const char *input)
{
	pid_t c_pid = fork();

	if (c_pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		char *args[150];
		int args_count = 0;

		char *tkn = strtok((char *)input, " ");

		while (tkn != NULL)
		{
			args[args_count++] = tkn;
			tkn = strtok(NULL, " ");
		}
		args[args_count] = NULL;

		execvp(args[0], args);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
