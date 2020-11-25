#include "shell.h"

/**
  * exec - Receives an splitted line of strings
  * and executes the program and it's arguments
  *
  * @argv: A splitted line in tokens
  * @line: The 'line' pointer (used to free)
  * Return: 0
  */

int exec(char **argv, char *line)
{
	pid_t forkpid;
	int status;

	forkpid = fork();
	if (forkpid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Can't execute: ");
		free(line);
		freeargv(argv);
		_exit(0);
	}
	else if (forkpid == -1)
	{
		perror("Can't create child process");
		free(line);
		freeargv(argv);
		_exit(-1);
	}
	else
	{
		wait(&status);
	}
	freeargv(argv);
	free(line);
	return (0);
}
