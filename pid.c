#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
  * main - check the code.
  *
  * Return: 0 always success.
  */
int main(void)
{
	printf(" Current Process: %d\n Parent Process: %d\n", getpid(), getppid());
	return (0);
}
