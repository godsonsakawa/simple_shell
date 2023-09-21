#include "simple_shell.h"

/**
 * get_user_input - Read and process user input.
 *
 * This function reads a line of input from the user and removes the newline
 * character. It returns the input as a dynamically allocated string.
 *
 * Return: A pointer to the input string.
 */
char *get_user_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t chars_read;

	printf("$ ");

	chars_read = getline(&input, &len, stdin);

	if (chars_read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	input[strlen(input) - 1] = '\0';

	return (input);
}
