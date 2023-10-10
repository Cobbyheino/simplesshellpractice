#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strtok - prints lines
 *@str: string to be passed
 *Return: Array of string
 */

char **_strtok(char *str)
{
	char **array, *pass;
	int i = 0, j = 0;

	array = malloc(8 * sizeof(char *));
	if (array == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	pass = strtok(str, " ");
	while (pass != NULL)
	{
		while (pass[j])
		{
			if (pass[j] == '\n')
				pass[j] = '\0';
			j++;
		}
		array[i] = pass;
		i++;
		j = 0;
		pass = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
