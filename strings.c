#include "shell.h"
/**
 * _strlen - finds the string length
 * @s: string
 *
 * Return: the length of the sstring
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - concantenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: the derived string
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 *
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (src == 0 || dest == src)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: comparison
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != * s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
