#include "simple_shell.h"

#define BUFFER_SIZE 1024

/**
 * handle_builtin - Handle built-in shell commands.
 * @input: The input string from the user.
 *
 * This function checks if the input corresponds to a built-in command
 * (e.g., "exit", "env") and handles it accordingly.
 */
void handle_builtin(char *input)
{
	char command[BUFFER_SIZE];
	char argument[BUFFER_SIZE];
	
	if (strncmp(input, "exit ", 5) == 0)
	{
		int exit_status;

		if (sscanf(input + 5, "%d", &exit_status) == 1)
		{
			exit(exit_status);
		}

	}
	else if (strcmp(input, "env") == 0)
	{
		print_environment();
	}
	else if (strcmp(command, "cd") == 0)
	{
		if (sscanf(input + strlen(command), "%s", argument) != 1)
		{
			argument[0] = '\0';
		}

		handle_cd(argument);
	}
	else if (strncmp(input, "setenv", 7) == 0)
	{
		char variable[BUFFER_SIZE];
		char value[BUFFER_SIZE];

		if (sscanf(input + 7, "%s %s", variable, value) == 2)
		{
			if (setenv(variable, value, 1) == -1)
			{
				perror("setenv");
			}
		}
	}
	else if (strncmp(input, "unsetenv ", 9) == 0)
	{
		char variable[BUFFER_SIZE];

		if (sscanf(input + strlen(command), "%s", variable) == 1)
		{
			if (unsetenv(variable) == -1)
			{
				perror("unsetenv");
			}
		}
	}
}

/**
 * handle_cd - Handle the cd built-in command.
 * @argument: The argument for the cd command (directory or "-").
 *
 * This function changes the current directory based on the given argument.
 * If no argument is given, it changes to the home directory.
 * If the argument is "-", it changes to the previous directory.
 * It also updates the environment variable PWD.
 */
void handle_cd(char *argument)
{
	char current_dir[BUFFER_SIZE];
	char previous_dir[BUFFER_SIZE];

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (argument[0] == '\0')
	{
		argument = getenv("HOME");
	}
	else if (strcmp(argument, "-") == 0)
	{
		argument = getenv("OLDPWD");
	}

	strcpy(previous_dir, current_dir);

	if (chdir(argument) == -1)
	{
		perror("chdir");
		return;
	}

	if (setenv("OLDPWD", previous_dir, 1) == -1)
	{
		perror("setenv");
		return;
	}

	if (setenv("PWD", argument, 1) == -1)
	{
		perror("setenv");
	}
}
