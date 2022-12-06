#include "header.h"
/**
 *main-function for infinite loop
 *@env: environment
 *@ac: arguments count
 *Return: infinite loop to display prompt and read lines
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line = NULL, **tokens = NULL, *path = NULL;
	size_t buflen = 0;
	int flag, count = 0, i = 0;

	while (1)
	{
		line = NULL;
		buflen = 0;
		if (isatty(0))
		{
			write(1, "$ ", 2);
		}
		flag = getline(&line, &buflen, stdin);
		if (flag == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[0] == '\n' || line[0] == ' ')
		{
			free(line);
			line = NULL;
			continue;
		}
		if (line[0] == 27)
		{
			execve(line, av, NULL);
			perror("./hsh");
			continue;
		}
		tokens = split_input(line, " \n");
		free(line);
		if (_strcmp(tokens[0], "env") == 0)
		{
			while (env[i])
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
				i++;
			}
			count = cmdcount();
			free_grid(tokens);
			continue;
		}
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_grid(tokens);
			exit(0);
		}
		execute(path, tokens, av, env, count);
	}
	free(path);
	free_grid(tokens);
	free(line);
	return(0);
}
