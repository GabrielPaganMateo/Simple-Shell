#include "header.h"
/**
 * builtin - Execute builtin commands
 * @tokens: Tokens from getline and split input
 * @env: External environment
 * Return: 0, if env is called, else exit the program
 */
int builtin(char **tokens, char **env)
{
	int i = 0;

	if (_strcmp(tokens[0], "env") == 0)
	{
		while (env[i])
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
			i++;
		}
		free_grid(tokens);
		return (0);
	}
	if (_strcmp(tokens[0], "exit") == 0)
	{
		free_grid(tokens);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

