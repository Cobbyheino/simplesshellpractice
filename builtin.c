#include "shell.h"
/**
 * inbuilt - function to check for in built command
 * @str: string to check for inbuilt command
 * Return: 1 if false and 0 for true
 */
int inbuilt(char *str)
{
	char **array;
	int x = 0;
	char *usrname;

	array = malloc(sizeof(char *) * 5);
	if (array == NULL)
		return (0);
	array[0] = "exit";
	array[1] = "cd";
	array[2] = "hello";
	for (x = 0; x < 3; x++)
	{
		if (_strcmp(array[x], str) == 0)
		{
			break;
		}
		x++;
	}
	x++;
	switch (x)
	{
	case 1:
		chdir(str);
		free(array);
		return (1);
	case 2:
		printf("bye");
		free(array);
		return (2);
	case 3:
		usrname = getenv("HOSTNAME");
		printf("Hello %s\n", usrname);
		free(array);
		return (1);
	default:
		free(array);
		return (0);
	}
	return (0);
}
