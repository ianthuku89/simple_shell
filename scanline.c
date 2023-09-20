#include "shell.h"
/**
 * scan_line - reads the inputted line
 *
 * Return: the inputted line
 */
char *scan_line(void)
{
	char *s = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&s, &len, stdin);
	if (n == -1)
	{
		free(s);
		return (NULL);
	}
	return (s);
}
