#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 100
/**
  * main - Unix commandline interpreter/ simple shell
  *
  * Return: 0 on success.
  */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int status, i = 0;
	char *argv[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = 0;
		/* Split command into arguments */
		char *token = strtok(command, " ");

		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
		/* Check for built-in commands */
		if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}
		pid_t child_pid = fork();

		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			/* If execve returns, it must have failed */
			perror("./shell");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
