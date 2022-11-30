#include "header.h"
/**
 * execute - function to execute commands from command line
 * @arguments: arguments passed to the command line
 * @env: environment
 * Return: Always 0 success
 */
int execute(char **tokens, char **env)
{
	pid_t childID;
	int status;
	int i = 0;

	childID = fork();

	if (childID == -1)
	{
		return (-1);
	}
	else if (childID == 0)
	{
		int val = execve(tokens[0], tokens, env);

		if (val == -1)
		{
			perror("./hsh");
		}

	}
	else
	{
		wait(&status);

		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	return (0);
}
