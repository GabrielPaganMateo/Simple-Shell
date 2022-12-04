#include "header.h"
/**
 * _strstr - locate a substring
 * @haystack: string
 * @needle: substring
 * Return: Pointer to beginnig of located substring
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (needle[0] == '\0')
	{
		return (haystack);
	}

	for (i = 0 ; haystack[i] != '\0' ; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0 ; needle[j] != '\0' ; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (needle[j] == '\0')
			{
				return (haystack + i);
			}
		}
	}
	return ('\0');
}
