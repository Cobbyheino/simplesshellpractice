#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * filechecker - checks for existence of system command exist.
 * @strg: str to check
 * Return: Null if false or append
 */

char *filechecker(char *strg)
{
	DIR *dir = opendir("/bin/");
	char *temp;
	char *appnd;
	struct dirent *doc;

	if (dir == NULL)
		return (NULL);
	doc = readdir(dir);
	while (doc != NULL)
	{
		temp = doc->d_name;
		if (_strcmp(temp, strg) == 0)
		{
			appnd = _strcat("/bin/", strg);
			closedir(dir);
			return (appnd);
		}
		doc = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
