#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
  * main -  a program to describe the concept of fork syscall.
  * Return: 0 if successful else 1.
  */
int main(void)
{
	int a = 40;
	printf("Before forking my pId is: %d\n", getpid());
	pid_t childProcessId = fork();

	printf("%d\n", a);
	printf("Parent pId: %lu\nChild pId: %lu\n", getppid(), getpid());
	printf("I'm done Printing\n");
	return (0);
}
