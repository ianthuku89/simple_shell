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
