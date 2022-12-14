#include <stdio.h>
/**
  * main - check the code
  * @argc: number of arguments.
  * @argv: array of strings on the terminal.
  * Return: 0 success.
  */
int main(int argc, char **argv)
{
	(void) argc;
	int i = 0;

	while (argv[i])
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}
