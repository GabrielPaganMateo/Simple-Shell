#include "header.h"
/**
 *get_path-function to get the PATH directories
 *@env: environment variables
 *Return: copy of path from index position
 */
char *get_path(char **env)
{
	int i = 0;
	char *path, **copy_path;

	while (env[i] != NULL)
	{
		if (_strncmp(env[i], "PATH", 4) == 0)
		{
			path = malloc(sizeof(char) * _strlen(env[i]));
			_strcpy(path, env[i]);
			copy_path = split_input(path, "=");
			_strcpy(path, copy_path[1]);
			free_grid(copy_path);
			return (path);
		}
		i++;
	}
	return (NULL);
}
/**
 * split_dirs-function to tokenize the directories
 * @path: pointer to the array of directories
 * Return: directories divided
*/
char **split_dirs(char *path)
{
	char **dirs;

	dirs = split_input(path, ":");
	return (dirs);
}
/**
 *add_path-function to concatenate command to directory
 *@tokens: arguments passed to command line
 *@dirs: pointer to array of directories
 *Return: command concatenated to current directory
 */
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
