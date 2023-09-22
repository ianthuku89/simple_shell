#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIMITER " \t\n"
extern char **environ;

char *scan_line(void);
char **tokenize(char *line);
int _execute(char **command, char **argv, int index);
void freearray(char **arr);
char *_getenv(char *vari);
char *_getpath(char *command);
char *_itoa(int n);
void reverse_string(char *str, int len);
void print_error(char *name, char *cmd, int index);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
