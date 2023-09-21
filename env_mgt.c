#include "simple_shell.h"

/**
 * print_environment - Print the current environment variables.
 *
 * This function prints the environment variables that are currently set
 * using the `environ` variable. Each environment variable is printed on
 * a separate line.
 */
void print_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
