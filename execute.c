#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * execute - execute input
 * @str: strings from input
 * @envp: Environment variables
 * Return: void
 */

void execute(char **str, char **envp)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: Fork error");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(str[0], str, envp) == -1)
			perror("./shell: No such file or directory");
	}
	else
	{
		wait(&status);
	}
}
