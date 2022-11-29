#include <stdlib.h>
#include <string.h>
/**
 * split_input
 */
char** split_input(char *line)
{
	int length 0;
	int capacity 16;
	char **arguments = malloc(capacity * sizeof(char *));

	char *delimiters = " \t\r\n";
	char *argument = strtok(line, delimiters);

	while (argument != NULL)
	{
		arguments[length] = argument;
		length++;

		argument = strtok(NULL, delimiters);
	}

	arguments[length] = NULL;
	return (arguments);
}
