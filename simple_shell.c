#include "header.h"
/**
 *main-function for infinite loop
 *@env: environment
 *@ac: arguments count
 *Return: infinite loop to display prompt and read lines
 */
int main()
{
	char *line;
	char **tokens;
	size_t buflen = 0;
	int mode = 1;

	while (1)
	{

			mode = isatty(STDIN_FILENO);
			if (mode == 1)
			{
				write(1, "$ ", 2);
			}

		getline(&line, &buflen, stdin);
		tokens = split_input(line);

		if (tokens[0] != NULL)
		{
			execute(tokens);
		}
	}
	free(line);
	return(0);
}
