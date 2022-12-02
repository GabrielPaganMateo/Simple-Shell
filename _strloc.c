#include "header.h"
/**
 * *_strpbrk - locate ocurrence of string s in any byte of string accept
 * @s: string evaluated
 * @accept: string with desired characters
 * Return: Characters
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	do {
		for (i = 0 ; accept[i] != '\0' ; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	} while (*s);
	return (0);
}
