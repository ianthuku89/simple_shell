#include "shell.h"
/**
 * main - start point
 * @argc: argument count
 * @argv: arguments
 * Return: 0 for success
 */
int main(int argc, char **argv)
{
	char *s = NULL;
	char **command = NULL;
	int status = 0;

	(void) argc;
	while (1)
	{
		s = scan_line();
		if (s  == NULL)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "n", 1);
			return (status);
		}
		command = tokenize(s);
		if (!command)
		{
			free(s);
			continue;
		}
		status = _execute(command, argv);
		free(s);
	}
	return (status);
}
