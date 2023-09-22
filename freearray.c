#include "shell.h"
/**
 * freearray - frees array of string
 * @arr: array to free
 */
void freearray(char **arr)
{
	int a;

	if (!arr)
		return;

	for (a = 0; arr[a]; a++)
	{
		free(arr[a]);
		arr[a] = NULL;
	}
	free(arr), arr = NULL;
}
/**
 * print_error - prints error
 * @name: print name
 * @cmd: prints command
 * @index: shows index
 */
void print_error(char *name, char *cmd, int index)
{
	char *idx, message[] = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, message, _strlen(message));

	free(idx);
}
