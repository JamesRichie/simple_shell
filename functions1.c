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
		perror("exec");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

/**
 * parse_cmd - determines the type of the command
 * @cmd: command to be parsed
 *
 * Return: constant representing the type of the command
 * Description - EXT_COMMAND -> commands like /bin/ls
 *		 INT_COMMAND -> commands like exit, env
 *		 PATH_COMMAND -> PATH commands like ls
 *		 INV_COMMAND -> invalid commands
 *

int parse_cmd(char *cmd)
{
	int i = 0;
	char *internal_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (EXT_COMMAND);
	}
	while (internal_cmd[i] = NULL)
	{
		if (_strcmp(cmd, internal_cmd[i]) == 0)
			return (INT_COMMAND);
	}
	
	path = _check(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INV_COMMAND);
}
*/

/**
 * _check - checks if a command is found in the PATH
 * @cmd: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 *

char *_check(char *cmd)
{
	char **path_array = NULL;
	char *tmp, *tmp2, *path_cpy;
	char *path = _getenv("PATH");
	int x;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	path_array = tokenizer(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = _strcat(path_array[i], "/");
		temp = _strcat(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}
*/
