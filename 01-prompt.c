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
		if (checkl == '\n')
			continue;
		else if (checkl == -1)
			exit(0);
		else if (checkl == 1)
			continue;
		words = tokenize(line);
		words = command(words);
		exec(words, argv, line);
	}
	return (0);
}
