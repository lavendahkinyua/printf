#include "main.h"

/**
 * _strlen - computes the lenght of a string
 * Prototype: int _strlen(const char *s);
 * @s: string
 * Return: number of characters of a string
 */
int _strlen(const char *s)
{
	if (*s)
		return (1 + _strlen(s + 1));
	return (0);
}

/**
 * _strcmp - compares two strings
 * Prototype: int _strcmp(const char *s1, const char *s2);
 * @s1: string
 * @s2: string
 * Return: 0 if identical;
 * negative intger if s1 less than s2;
 * otherwise a positive integer.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strdup - duplicate a given string
 * Prototype: char *_strdup(char *str);
 * @str: string to be duplicated
 * Return: a pointer to the newly allocated space in memory which
 * conains a copy of the string given as parameter
 */

char *_strdup(char *str)
{
	char *dup;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = (char *)malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

/**
 * rev_str - reverses a string
 * @s: string to reverse
 */
void rev_str(char *s)
{
	char tmp;
	int i, len, len1;

	len = 0;
	len1 = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	len1 = len - 1;

	for (i = 0; i < len / 2; i++)
	{
		tmp = s[i];
		s[i] = s[len1];
		s[len1--] = tmp;
	}
}
