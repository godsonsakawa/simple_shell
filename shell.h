#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 1000

char *path_command(char *command);

#endif /* _SHELL_H_ */
