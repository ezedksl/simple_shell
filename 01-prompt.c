#include "shell.h"
/**
  * main - Prints the prompt in a loop and calls
  * the functions to get an input line and handle the parameters
  * @argc: argument count on command line.
  * @argv: arguments passen on command line.
  * Return: 0
  */

int main(int argc, char **argv)
{
	struct stat st;
	int getlineRet = 0, flag = 0, checkl = 0;
	size_t linebuf = 0;
	char **words = NULL, *line = NULL;

	(void)argc;
	while (1)
	{
		line = NULL;
		if (isatty(STDIN_FILENO))
		{
			flag = 1;
			write(STDOUT_FILENO, "$ ", 2);
		}
		getlineRet = getline(&line, &linebuf, stdin);
		if (getlineRet == EOF || getlineRet == -1)
		{
			free(line);
			if (flag == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		checkl = linecheck(line);
		if (checkl == '\n' || checkl == 1)
			continue;
		else if (checkl == -1)
			exit(0);
		words = tokenize(line);
		words = command(words);
		if (stat(words[0], &st) == -1)
		{
			perror(argv[0]);
			free(line);
			freeargv(words);
			continue;
		}
		exec(words, argv, line);
	}
	return (0);
}
