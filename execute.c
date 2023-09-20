#include "shell.h"
/**
 * _execute - executes program
 * @command: user commands
 * @argv: arguments
 *
 * Return: status
 */
int _execute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, envi) == -1)
		{
			perror(argv[0]);
			freearray(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(command);
	}
	return (WEXITSTATUS(status));
}
