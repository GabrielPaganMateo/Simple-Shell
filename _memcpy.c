#include "main.h"
/**
 *_memcpy - copy memory to destination
 *@dest: destination
 *@src: memory to copy
 *@n: number of bytes
 *Return: destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int b;

	b = 0;

	while (b < n)
	{
		dest[b] = src[b];
		b++;
	}
	return (dest);
}

