#include "header.h"
/**
 *main-principal function for simple shell
 *Return: infinite loop to display prompt and read lines
 */
int main(void)
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
			execute(tokens);
		}
		free(tokens);
		free(line);
	}
}
