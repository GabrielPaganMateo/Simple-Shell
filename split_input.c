#include "header.h"
/**
 * split_input-function to divide arguments on command line
 * @line: pointer to input string
 * Return: arguments splitted
 */
char **split_input(char *line)
{
	int length = 0;
	char **arguments = malloc(strlen(line) * (sizeof(char *)));

	char *delimiters = " \t\r\n";
	char *argument = strtok(line, delimiters);

	while (argument != NULL)
	{
		arguments[length] = argument;
		length++;

		argument = strtok(NULL, delimiters);
	}

	arguments[length] = NULL;
	return (arguments);
}
