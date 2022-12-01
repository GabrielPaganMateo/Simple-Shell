#include "header.h"
/*
 *
 */
int get_path()
{
	int i = 0, j = 0, k = 0;
	extern char **environ;
	char *path = NULL;
	char *token = NULL;
	char **dirs = NULL;

	while (environ[i] != NULL)
	{
		if (strcmp(environ[i], "PATH") == 0)
		{
			break;
		}
		i++;
	}

	path = environ[i];

	token = strtok(path, ":");

	while (token != NULL)
	{
		_strcpy(dirs[j], token);
		token = strtok(NULL, ":");
		j++;
	}

	while (dirs[k] != NULL)
	{
		chdir(dirs[k]);
	}
	return(0);
}
