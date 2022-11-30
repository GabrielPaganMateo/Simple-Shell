#include "header.h"
/**
 * execute - function to execute commands from command line
 * @arguments: arguments passed to the command line
 * @env: environment
 * Return: Always 0 success
 */
int execute(char **arguments, char **env)
{
	pid_t childID;
	int status;
	int i = 0;

	childID = fork();

	if (childID == -1)
	{
		return (-1);
	}
	if (childID == 0)
	{
		int val = execve(arguments[0], arguments, env);

		if (val == -1)
		{
			perror("./hsh");
		}
	}
	else
	{
		wait(&status);

		while (arguments[i])
		{
			free(arguments[i]);
			i++;
		}
		free (arguments);
	}
	return (0);
}
