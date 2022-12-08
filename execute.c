#include "header.h"
/**
 *error_msg-function to display error message
 *@av: array of arguments
 *@count: number of error
 *@tokens: arguments in the command line tokenized
 */
void error_msg(char **av, int count, char **tokens)
{
	char *CS = ": ";
	char *NF = "not found\n";

	write(2, av[0], _strlen(av[0]));
	write(2, CS, 2);
	dprintf(STDERR_FILENO, "%i", count);
	write(2, CS, 2);
	write(2, tokens[0], _strlen(tokens[0]));
	write(2, CS, 2);
	write(2, NF, _strlen(NF));
	exit(127);
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
	int status;
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
		if (cmd != NULL || tokens != NULL)
		if (execve(cmd, tokens, env) == -1)
		{
			count = cmdcount();
			error_msg(av, count, tokens);
		}
	}
	else
	{
		wait(&status);
		free_grid(tokens);
	}
	free(line);
	count = cmdcount();
	return (0);
}
