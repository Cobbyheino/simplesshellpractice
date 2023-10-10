#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>

char *_strcat(char *dest, char *sour);
int _strcmp(char *s1, char *s2);
void execute(char **str, char **envp);
char **_strtok(char *str);
int pathchecker(char *cstr);
char *filechecker(char *strg);
int myownexit(char **args);
int inbuilt(char *str);

#endif
