#include "header.h"
/**
 *main-function for infinite loop
 *@env: environment
 *@ac: arguments count
 *Return: infinite loop to display prompt and read lines
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	char *line;
	char **tokens;
	size_t buflen = 0;
	int i = 0;

	if (isatty(0))
	{
		while (1)
		{
			write(1, "$ ", 2);
			getline(&line, &buflen, stdin);
			if (_strcmp(line, "exit\n") == 0)
			{
				free(line);
				line = NULL;
				exit(0);
			}
			if (_strcmp(line, "env\n") == 0)
			{
				while (env[i])
				{
					write(1, env[i], _strlen(env[i]));
					write(1, "\n", 1);
					i++;
				}
			}
			tokens = split_input(line);
			if (tokens[0])
			{
				execute(tokens, env);
			}
		}
	}
	else
	{
		getline(&line, &buflen, stdin);
		if (_strcmp(line, "exit\n") == 0)
		{
			exit(0);
		}
		if (_strcmp(line, "env\n") == 0)
		{
			while (env[i])
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
				i++;
			}
		}
		tokens = split_input(line);
		if (tokens[0])
		{
			execute(tokens, env);
		}
		return(0);
	}
	free(line);
	return(0);
}
