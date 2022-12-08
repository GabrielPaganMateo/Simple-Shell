#include "header.h"
/**
 * specialcase - confirms if command line has ^[[C or \n
 * @line - line obtained from getline
 * @env - external environment
 * @av - command line arguments
 * Return: 0 if \n or ^[[C edge case, else return 1
 */
int specialcase(char *line, char **av)
{
	if (line[0] == '\n')
	{
		free(line);
		line = NULL;
		return (0);
	}
	if (line[0] == 27)
	{
		execve(line, av, NULL);
		perror("./hsh");
		return(0);
	}
	return(1);
}
