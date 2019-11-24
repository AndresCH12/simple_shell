#include "holberton.h"

int findpath(char **command, char **env)
{
	char *left = NULL, *right = NULL, *bins, *token, *envdup, *path = NULL;
	size_t i, j, len1 = 0, len2 = 0;

	for (i = 0; env[i]; i++)
	{
		envdup = _strdup(env[i]);
		left = strtok(envdup, "=");
		right = strtok(NULL, "=");
		if (_strcmp(left, "PATH") == 0)
		{
			bins = right;
			token = strtok(bins, ":");
			for (j = 0; token; j++)
			{
				len1 = _strlen(token);
				len2 = _strlen(command[0]);
				path = malloc(sizeof(char) * (len1 + len2 + 2));
				path = cat(path, token, command);
				if (access(path, X_OK) == 0)
				{
					if (fork() == 0)
						execve(path, command, NULL);
					else
						wait(NULL);
					free(path);
					free(envdup);
					return (0);
				}
				token = strtok(NULL, ":");
				free(path);
			}
		}
		free(envdup);
	}
	return (1);
}
