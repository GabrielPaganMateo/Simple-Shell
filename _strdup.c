#include "header.h"
/**
 *_strdup-function to duplicate strings
 *@s: pointer to string
 *Return: string duplicate it
 */
char *_strdup(const char *s)
{
	size_t len;
	char *copy;

	len = _strlen(s) + 1;

	copy = malloc(sizeof(len));

	if (copy)
	{
		_memcpy(copy, s, len);
	}
	return (copy);
}
