#include "shell.h"

#define BUFFER_SIZE 256
/**
  * main - check the code.
  *
  * Return: 0 always success.
  */
int main(int argc, char **argv)
{
	while (1)
	{
		printf("#cisfun$ ");

		char *line = NULL;
		size_t line_size = 0;
		if (argc > 1)
		{
			line = argv[1];
			line_size = strlen(line);
		}
		else
		{
			int read = getline(&line, &line_size, stdin);
			if (read == -1)
			{
				printf("\n");
				break;
			}
		}
		line[strcspn(line, "\n")] = 0;

		char *command = strtok(line, " ");
		char *args[BUFFER_SIZE];
		int i = 0, status;

		while (command != NULL)
		{
			args[i++] = command;
			command = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid_t pid = fork();
		
		if (pid == 0)
		{
			execve(args[0], args, NULL);
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
