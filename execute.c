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
	int j = 0, status;
	struct stat sb;
	(void)line;

	childID = fork();
	if (childID == -1)
		perror("Error");
	else if (childID == 0)
	{
		if (stat(tokens[0], &sb) == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				count = cmdcount();
				error_msg(av, count, tokens);
			}
		}
		path = get_path(env);
		dirs = split_dirs(path);
		cmd = add_path(tokens, dirs);

		execve(cmd, tokens, env);
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
	free(line);
	count = cmdcount();
	return (0);
}
