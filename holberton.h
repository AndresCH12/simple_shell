#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void printenv(char **env);
char **tokens(char *str);
char *_strcat(char *dest, char *src);
char *findpath(char **command, char **env);

#endif
