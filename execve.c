#include <stdio.h>
#include <unistd.h>

/**
  * main - entry point of the program.
  *
  * Return: 0.
  */
int main(void)
{
	int x;
	char *argv[] = {"/usr/bin/ls", "-lha", NULL};

	x = execve(argv[0], argv, NULL);
	if (x == -1)
		printf("execve failed\n");
	else
		printf("This does'nt print\n");

	return (0);
}
