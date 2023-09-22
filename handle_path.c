#include "shell.h"
/**
 * _getpath - gets command
 * @command: user commmand
 * Return: 0
 */
char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int x;
	struct stat st;

	for (x = 0; command[x] == '/')
	{
		{
		if (stat(command, &st) == 0)
			return (_strdup(command));

		return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command)

		if (full_cmd)
		{
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, command);
		if (stat(full_cmd, &st) == 0)
		{
		free(path_env);
		return (full_cmd);
		}
		free(full_cmd), full_cmd = NULL;

		dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}

