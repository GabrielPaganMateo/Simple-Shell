#include "header.h"
/**
 *error_msg-function to display error message
 *@av: array of arguments
 *@count: number of error
 *@tokens: arguments in the command line tokenized
 */
void error_msg(char **av, int count, char **tokens)
{
	_printf("%s: ", av[0]);
	 _printf("%i: ", count);
	_printf("%s: not found\n", tokens[0]);
	exit(EXIT_FAILURE);
}
/**
 * execute - function to execute commands from command line
 * @tokens: arguments passed to the command line
 * @env: pointer to environment variables
 * @line: pointer to command line
 * @count: number of error
 * @av: array of arguments
 * Return: Always 0 success
 */
int execute(char *line, char **tokens, char **av, char **env, int count)
{
	char *path, **dirs, *cmd;
	pid_t childID;
	unsigned int i = 0;
	int j = 0, status;
	(void)line;

	path = get_path(env);
	dirs = split_dirs(path);
	cmd = add_path(tokens, dirs);
	childID = fork();
	if (childID == -1)
		perror("Error");
	else if (childID == 0)
	{
		if (_strcmp(tokens[0], "env") == 0)
		{
			while (env[i])
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
				i++;
			}
			count = cmdcount();
			return (1);
		}
		else if (execve(cmd, tokens, env) == -1)
		{
			count = cmdcount();
			error_msg(av, count, tokens);
		}
	}
	else
	{
		wait(&status);
		j = 0;
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
	}
	free(path);
	free(dirs);
	free(line);
	count = cmdcount();
	return (0);
}
