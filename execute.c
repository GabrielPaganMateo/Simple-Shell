#include "header.h"
/**
 * execute - function to execute commands from command line
 * @tokens: arguments passed to the command line
 * @env: pointer to environment variables
 * Return: Always 0 success
 */
int execute(char *line, char **tokens, char **env)
{
	pid_t childID;
	unsigned int i = 0;
	int j = 0, status;

	(void)line;
	childID = fork();
	if (childID == -1)
		perror("Error");
	else if (childID == 0)
	{
		if (_strcmp(tokens[0], "env") == 0)
		{
			while (env[i])
			{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
			i++;
			}
			return (1);
		}
		else if (execve(tokens[0], tokens, env) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		j = 0;
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
	}
	return (1);
}
