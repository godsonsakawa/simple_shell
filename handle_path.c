#include "simple_shell.h"

/**
 * handle_path - find the full path of a command
 *             using the PATH environment variable.
 * @command: The command to search for.
 *
 *
 * Return: string contained the full path to the command.
 */
char *handle_path(char *command)
{
	char *path = getenv("PATH");
	char *token;
	char *full_path = NULL;

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not set.\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		/* Construct full path */
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* Combine the directory path with the command */
		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}

	return (NULL);
}
