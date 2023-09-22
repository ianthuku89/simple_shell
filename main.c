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
	int index = 0;

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

		index++;
		command = tokenize(s);
		if (!command)
		{
			continue;
		}
		status = _execute(command, argv, index);
	}
	return (status);
}
