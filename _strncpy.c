#include "header.h"
/**
 * *_strncpy - Copy a string
 * @dest: copy destination
 * @src: string to be copied
 * @n: size of string
 * Return: String of characters
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
		i++;
		dest[i] = '\0';
	return (dest);
}

