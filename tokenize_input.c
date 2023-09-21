#include "simple_shell.h"

/**
 * tokenize_input - Tokenize input into commands and arguments.
 * @input: The user input string to tokenize.
 *
 *
 * This function tokenizes input string to extract the command & arguments.
 *
 * Return: A pointer to the dynamically allocated array of strings.
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *token;
	int token_count = 0;
	const char delimeter[] = " \t\n";

	token = strtok(input, delimeter);
	while (token != NULL)
	{
		tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
		if (tokens  == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token_count++;
		token = strtok(NULL, delimeter);
	}
	tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	tokens[token_count] = NULL;

	return (tokens);
}
