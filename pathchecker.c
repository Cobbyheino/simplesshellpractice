#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * pathchecker - check if the string has path "/bin/"
 * @cstr: string to be checked
 *
 * Return: 0 no path false and 1 path is found
 */

int pathchecker(char *cstr)
{
	char *comp = "/bin/", *ptr, *j;
	int a = 0, m = 0;

	ptr = malloc(sizeof(char) * 50);

	if (ptr == NULL)
		return (0);
	while (comp[a] != '\0')
	{
		if (comp[a] != cstr[a])
		{
			free(ptr);
			return (0);
		}
		a++;
	}
	while (cstr[a] != '\0')
	{
		ptr[m] = cstr[a];
		m++;
		a++;
	}
	ptr[m] = '\0';
	j = filechecker(ptr);
	if (j != NULL)
	{
		free(ptr);
		return (1);
	}
	return (0);
}
