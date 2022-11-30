#include "header.h"
/**
 * split_input-function to divide arguments on command line
 * @line: pointer to input string
 * Return: arguments splitted
 */
char **split_input(char *line)
{
	int length = 0;
	char **tokens = malloc(_strlen(line) * sizeof(char *));
	char *delimiters = " \n";
	char *token = strtok(line, delimiters);

	if (tokens == NULL)
	{
		return (NULL);
	}

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}
