#include "header.h"
/*
 *
 */
char *get_path(char **env)
{
	int i = 0;
	char *path, **copy_path;

	while (env[i] != NULL)
	{
		if (_strncmp(env[i], "PATH", 4) == 0)
		{
			path = strdup(env[i]);
			copy_path = split_input(path, "=");
			free(path);
			path = strdup(copy_path[1]);
			free_grid(copy_path);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char **split_dirs(char *path)
{
	int i = 0;
	char **dirs;
	char *token;


	dirs = split_input(path, ":");
	return (dirs);
}


int main(int ac, char **av, char **env)
{
	int i;
	char *BRRR;
	char **UAA;

	(void)ac;
	(void)av;

	BRRR = get_path(env);
	printf("%s\n", BRRR);
	UAA = split_dirs(BRRR);

	printf("%s\n", BRRR);

	for (i = 0; UAA[i] != NULL; i++)
	{
		printf("%s\n", UAA[i]);
	}

	return (0);
}
