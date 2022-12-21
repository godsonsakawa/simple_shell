#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 100

int main(void) {

	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);

		// Remove trailing newline character
		command[strcspn(command, "\n")] = 0;

		// Split command into arguments
		char *argv[MAX_COMMAND_LENGTH];
		int i = 0;
		char *token = strtok(command, " ");
		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
		// Check for built-in commands
		if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}
		else if (strcmp(argv[0], "/usr/bin/ls") == 0)
		{
			//Execute ls command
			char *ls_argv[] = {"ls", "-l", NULL};
			execve(argv[0], ls_argv, NULL);
		}

		// Create child process
		pid_t child_pid = fork();
		if (child_pid == 0)
		{
			// Execute command in child process
			execve(argv[0], argv, NULL);
			// If execve returns, it must have failed
			perror("execve");
			exit(1);
		}
		else
		{
			// Wait for child process to finish
			int status;
			wait(&status);
		}
	}
	return 0;
}

