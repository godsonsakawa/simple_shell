#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

/* Function prototypes */
char *get_user_input(void);
void execute_command(char *command, char **args);
char **tokenize_input(char *input);
char *handle_path(char *command);
void print_environment(void);
void handle_builtin(char *input);
void handle_cd(char *argument);

#endif /* SIMPLE_SHELL_H */
