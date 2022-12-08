#include "header.h"
/**
 * _strncmp - compares n bytes of a string
 * @s1: first string
 * @s2: second string
 * @n: amount of bytes
 * Return: pointer
 */
int _strncmp(char *s1, char *s2, int n)
{
	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)-- s2);
		if (*s1++ == 0)
			break;
	} while (--n != 0);
	return (0);
}

