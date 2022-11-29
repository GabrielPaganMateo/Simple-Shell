#include "header.h"
/**
 *main-principal function for simple shell
 *Return: infinite loop to display prompt and read lines
 */
int main(void)
{
	while (1)
	{
		write(1, "$ ", 2);

	  char *line = read_line();
		char **tokens = split_input(line);

		if (tokens[0] != NULL)
		{
			execute(tokens);
		}
		free(tokens);
		free(line);
	}
}
