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
			path = _strdup(env[i]);
			copy_path = split_input(path, "=");
			free(path);
			path = _strdup(copy_path[1]);
			free_grid(copy_path);
			return (path);
		}
		i++;
	}
	return (NULL);
}
/*
*/
char **split_dirs(char *path)
{
	char **dirs;

	dirs = split_input(path, ":");
	return (dirs);
}
/**/
char *add_path(char **tokens, char **dirs)
{
	char *cmd;
	int i = 0;
	struct stat sb;

	while (dirs[i] != NULL)
	{
		if (_strstr(dirs[i], tokens[0]) != NULL)
		{
			break;
		}
		i++;
	}
	i = 0;
	while (dirs[i] != NULL)
	{
		cmd = _strcat(dirs[i], tokens[0]);
		if (stat(cmd, &sb) == 0)
		{
			tokens[0] = cmd;
			break;
		}
		i++;
	}
	return (tokens[0]);
}

