#include "header.h"
/*
 *
 */
char *_strcat(char *dest, char *src)
{
	int dlength, i;

	dlength = 0;

	while (dest[dlength] != '\0')
	{
		dlength++;
	}

	for (i = 0 ; ; i++)
	{
		dest[dlength + i] = src[i];

		if (src[i] == '\0')
		{
		return (dest);
		}
	}
}
