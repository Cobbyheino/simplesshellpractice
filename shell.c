#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Main for simple shell
 * @argc: num of arguments
 * @argv: aray of args
 * @envp: aray of env variables
 * Return: Always 0
 */

int main(int argc, char **argv, char **envp)
{
	char **string;
	size_t n = 20, inbtt = 0, ptr = 4;
	ssize_t no_ofchar;
	char *buf, *ncc;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		buf = malloc(sizeof(char) * n);
		no_ofchar = getline(&buf, &n, stdin);
		if (no_ofchar == -1)
		{
			free(buf);
			exit(EXIT_FAILURE);
		}
		if (*buf != '\n')
		{
			string = _strtok(buf);
			if (_strcmp("exit", string[0]) == 0)
				break;
			inbtt = inbuilt(string[0]);
			ncc = filechecker(string[0]);
			if (inbtt == 0 && ncc != NULL)
				string[0] = ncc;
			ptr = pathchecker(string[0]);
			if (ptr == 1)
				execute(string, envp);
			if (ncc == NULL && ptr == 0 && inbtt == 0)
				printf("./shell: No such file or directory\n");
		}
	}
	free(buf);
	free(string);
	return (0);
}
