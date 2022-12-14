#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
  * main - check the code.
  *
  * Return: 0 always success.
  */
int main(void)
{
	char *buf = NULL, **tokens = NULL;
	size_t bytes = 10;
	int i = 0;

	buf = malloc(sizeof(char) * bytes);

	printf("$ ");
	if (buf == NULL)
	{
		printf("Malloc failed to allocate memory\n");
		return (0);
	}

	getline(&buf, &bytes, stdin);
	printf("%s", buf);

	tokens = malloc(strlen(buf));

	if (tokens == NULL)
	{
		printf("Error. Failed to allocate memory\n");
		return (0);
	}

	tokens[i] = strtok(buf, " ");

	while (tokens[i])
	{
		++i;
		tokens[i] = strtok(NULL, " ");
	}

	i = 0;
	while (tokens[i])
	{
		printf("tokens[%d]: %s\n", i, tokens[i]);
		i++;
	}

	return (0);
}
