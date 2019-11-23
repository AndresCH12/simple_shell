#include "holberton.h"
/**
 *main - is the entry point
 *@ac:  is the number of arguments passed
 *@av: is the argument passed
 *@env: is the enviroment
 *Return: always 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **command;
	char *new;
	size_t bufflen = 0, i;
	int status = 1;
	(void) ac, (void) av;

	while (status)
	{
		i = 0;
		write(STDOUT_FILENO, "$ ", 2);
		getline(&buffer,&bufflen,stdin);
		if(_strcmp(buffer, "\n") == 0)
			continue;
		for (; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		}
		if (_strcmp(buffer, "env") == 0)
		{
			printenvi(env);
		}
		if (_strcmp(buffer, "exit") == 0)
		{
			write(STDOUT_FILENO, "cya", 4);
			_putchar('\n');
			exit(EXIT_SUCCESS);
			free(buffer);
		}
		command = tokens(buffer);
		new = findpath(command, env);
		if (fork() == 0)
			execve(new, command,  NULL);
		else
			wait(NULL);
		free(buffer);
		free(command);
		buffer = NULL;
	}
	return (0);
}
