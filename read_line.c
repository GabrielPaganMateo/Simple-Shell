#include "header.h"
/**
 *read_line-function to read a single line of input from stdin
 *Return: line from stdin
 */
char *read_line()
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);

	return (line);
}
