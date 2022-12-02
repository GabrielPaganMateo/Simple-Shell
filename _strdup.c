#include "header.h"
/*
 *
 */
char *_strdup(char *str)
{
	int len;
	char *copy;

	len = strlen(str) + 1;
	if (!(copy = malloc((u_int)len)))
		return (NULL);
	memcpy(copy, str, len);
	return (copy);
}

