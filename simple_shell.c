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
	int flag, count = 0;

	(void)av;

	while (1)
	{
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
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_grid(tokens);
			free(line);
			exit(0);
		}
		execute(path, tokens, av, env, count);
	}
	return(0);
}
