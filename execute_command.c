#include "simple_shell.h"

/**
 * execute_command - Execute a command.
 * @command: The command to be executed.
 * @args: Command arguments.
 *
 * This function creates a child process to execute the specified command.
 * It uses the execve system call to replace the child process image with
 * the specified command.
 */
void execute_command(char *command, char **args)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		_exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *full_path;

		if (command[0] == '/' || command[0] == '.')
		{
			/* handle absolute/ relative paths */
			full_path = strdup(command);
		}
		else
		{
			full_path = handle_path(command);
		}
		if (full_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			_exit(EXIT_FAILURE);
		}
		if (execve(full_path, args, environ) == -1)
		{
			perror("execve");
			free(full_path);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &child_status, 0);
	}
}
