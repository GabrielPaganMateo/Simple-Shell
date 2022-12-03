#include "header.h"
/**
 * execute - function to execute commands from command line
 * @tokens: arguments passed to the command line
 * @env: pointer to environment variables
 * Return: Always 0 success
 */
int execute(char *line, char **tokens, char **av, char **env, int count)
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
			count = cmdcount();
			return (1);
		}
		else if (execve(tokens[0], tokens, env) == -1)
		{
			count = cmdcount();
			_printf("%s: ", av[0]);
			_printf("%i: ", count);
			_printf("%s: not found\n", tokens[0]);
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
	count = cmdcount();
	return (0);
}
