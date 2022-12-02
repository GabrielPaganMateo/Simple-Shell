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
		if (strncmp(env[i], "PATH", 4) == 0)
		{
			copy_path = split_input(env[i], "=");
			path = strdup(copy_path[1]);
			free_grid(copy_path);
			return (path);
		}
		i++;
	}
	return (NULL);
}
/*
char **split_dirs(char *path)
{
	int i = 0;
	char **dirs;
	char *token;


	token = strtok(path, ":");
	while (token != NULL)
	{
		dirs[i] = _strdup(token);
		token = strtok(NULL, ":");
		i++;
	}
	return (dirs);
}*/


int main(int ac, char **av, char **env)
{
	char *BRRR = NULL;

	(void)ac;
	(void)av;

	BRRR = get_path(env);
	printf("%s\n", BRRR);

	return (0);
}
