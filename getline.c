#include <stdio.h>
#include <stdlib.h>
/**
  * main - check the code.
  *
  * Return: 0 always success.
  */
int main(void)
{
	char *buf = NULL;
	size_t bytes = 10;

	buf = malloc(sizeof(char) * bytes);

	printf("$ ");
	if (buf == NULL)
	{
		printf("Malloc failed to allocate memory\n");
		return (0);
	}

	getline(&buf, &bytes, stdin);
	printf(" %s ", buf);

	return (0);
}
