#include "shell.h"
/**
 * _execute - executes program
 * @command: user commands
 * @argv: arguments
 * @index: the index needed
 *
 * Return: status
 */
int _execute(char **command, char **argv, int index)
{
	char *full_command;
	pid_t child;
	int status;

	full_command = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], index);
		freearray(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if ((full_command, command, environ) == -1)
		{
			free(full_command), full_command = NULL;
			freearray(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(command);
		free(full_command), full_command = NULL;
	}
	return (WEXITSTATUS(status));
}
