#include "header.h"
/**
 * _strcmp - Compares two string
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, less or greater than 0 if not equal
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}

		i++;
	}
	return (s1[i] - s2[i]);
}
