#include "shell.h"
#include <stdlib.h> // Include the necessary header file for malloc and free

char **tokenizer(char *line)
{
  char *token = NULL, *tmp = NULL;
  char **command = NULL;
  int cpt = 0, i = 0;

  if (!line)
      return (NULL);
  tmp = _strdup(line);

  token = strtok(tmp, DELIMITER);
  if (token == NULL) // Check if the first token is NULL
  {
    free(line); // Free the allocated memory
    free(tmp);
    return (NULL);
  }

  while (token)
  {
    cpt++;
    token = strtok(NULL, DELIMITER);
  }
  free(tmp);

  command = (char **)malloc(sizeof(char *) * (cpt + 1)); // Allocate memory for command

  if (!command)
  {
    free(line); // Free the allocated memory
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

