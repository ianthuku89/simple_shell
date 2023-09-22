#include "shell.h"
/**
 * _getenv - gets the env
 * @vari: variable
 *
 * Return: the env
 */
char *_getenv(char *vari)
{
	char *tmp, *token, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		token = strtok(tmp, "=");
		if (_strcmp(token, vari) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
}
