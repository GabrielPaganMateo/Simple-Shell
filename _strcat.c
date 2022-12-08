#include "header.h"
/**
 * *_strcat- concatenate string
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
	int dlength, i;

	dlength = 0;

	while (dest[dlength] != '\0')
	{
		dlength++;
	}

	dest[dlength] = '/';

	for (i = 0 ; ; i++)
	{
		dest[dlength + 1 + i] = src[i];

		if (src[i] == '\0')
		{
			return (dest);
		}
	}
}
