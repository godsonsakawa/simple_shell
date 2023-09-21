#include "simple_shell.h"

/**
 * main - Simple Unix shell.
 *
 * This program implements a simple Unix shell that displays a prompt,
 * reads user commands, executes them, and repeats the process until
 * the user enters "exit".
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *input;
	char **args;
	int i;

	while (1)
	{
		input = get_user_input();
		if (input == NULL)
		{
			printf("\n");
			break;
		}

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		else
		{
			handle_builtin(input);
		}

		args = tokenize_input(input);
		if (args != NULL && args[0] != NULL)
		{
			execute_command(args[0], args);

			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
		}

		free(input);
	}

	return (0);
}
