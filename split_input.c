#include "header.h"
/**
 * split_input-function to divide arguments on command line
 * @line: pointer to input string
 * @delimiter: pointer to delimiters
 * Return: arguments tokenized
 */
char **split_input(char *line, char *delimiter)
{
	int i = 0;
	char *token = NULL, **tokens = malloc(_strlen(line) * sizeof(char *));

	if (tokens == NULL)
		return (NULL);

	token = strtok(line, delimiter);
	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (tokens == NULL)
			return (NULL);
		_strcpy(tokens[i], token);
		i++;
		token = NULL;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;
	return (tokens);
}
