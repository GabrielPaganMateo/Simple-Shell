#include "header.h"
/**
 *main-function for infinite loop
 *@env: environment
 *@ac: arguments count
 *Return: infinite loop to display prompt and read lines
 */
int main(int ac __attribute__((unused)), char **env)
{
	char *line;
	char **tokens;

	while (1)
	{
		write(1, "$ ", 2);

		line = read_line();
		tokens = split_input(line);

		if (tokens[0] != NULL)
		{
			execute(tokens, env);
		}
		free(tokens);
		free(line);
	}
}
