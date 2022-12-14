#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf(" Current Process: %d\n Parent Process: %d\n", getpid(), getppid());
	return (0);
}
