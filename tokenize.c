#include "shell.h"
#include <stdlib.h>
/**
 * tokenize - creates tokens from user input
 * @line: user input
 *
 * Return: the commands from input
 */
char **tokenize(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int c = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIMITER);
	if (token == NULL)
	{
		free(line);
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		c++;
		token = strtok(NULL, DELIMITER);
	}
	free(tmp);
	command = (char **)malloc(sizeof(char *) * (c + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, DELIMITER);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}
	free(line);
	command[i] = NULL;
	return (command);
}
