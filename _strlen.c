#include "header.h"
/**
 * _strlen - Returns the length of a string
 * @s : string
 * Return: value of string length
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
