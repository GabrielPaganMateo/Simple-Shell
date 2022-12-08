#include "header.h"
/**
 *main-function for infinite loop
 *@env: environment
 *@ac: arguments count
 *@av: command line arguments
 *Return: infinite loop to display prompt and read lines
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line = NULL, **tokens = NULL, *path = NULL;
	size_t buflen = 0;
	int flag, count = 0;

	while (1)
	{
		line = NULL;
		buflen = 0;
		tokens = NULL;
		if (isatty(0))
			write(1, "$ ", 2);
		flag = getline(&line, &buflen, stdin);
		if (flag == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (specialcase(line, av) == 0)
		{
			count = cmdcount();
			continue;
		}
		tokens = split_input(line, " \n");
		free(line);
		if (tokens[0] != NULL)
		{
			if (builtin(tokens, env) == 0)
			{
				count = cmdcount();
				continue;
			}
			execute(path, tokens, av, env, count);
		}
		else
		free(tokens);
	}
	free(path);
	free_grid(tokens);
	free(line);
	return (0);
}
