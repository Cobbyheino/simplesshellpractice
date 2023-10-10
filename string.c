#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strcmp - check string values
 * @s1: enter input value
 * @s2: enter input value
 *
 * Return: s1[a] - s2[a]
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0')
	{
	if (s1[a] != s2[a])
		{
		return (s1[a] - s2[a]);
		}
	a++;
	}
	return (0);
}

/**
 * _strcat - to concantenates two strings
 * @dest: destination string
 * @sour: source string
 * Return: pointer to the new string
*/
char *_strcat(char *dest, char *sour)
{
	char *result = dest;

	while (*dest)
	{
	dest++;
	}
	while (*sour)
	{
	*dest++ = *sour++;
	}
	*dest = *sour;
	return (result);
}
