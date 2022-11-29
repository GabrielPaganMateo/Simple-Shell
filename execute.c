#include <sys/wait.h>
#include <unistd.h>
/*
 * execute
 */
void execute(char **arguments)
{
	pid_t childID = fork();

	if (childID == 0)
	{
		execve(arguments[0], arguments, NULL);
		perror("Error");
		exit;
	}
	else if (childID > 0)
	{
		int status;

		do {
			waitpid(childID, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	perror("Error");
}
