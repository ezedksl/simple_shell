#include "shell.h"
/**
  * main - Prints the prompt in a loop and calls
  * the functions to get an input line and handle the parameters
  *
  * Return: 0
  */

int main(void)
{
	int getlineRet = 0, flag = 0, checkl = 0;
	size_t linebuf = 0;
	char **argv = NULL, *line = NULL;

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
			break;
		else if (checkl == 1)
			continue;
		argv = tokenize(line);
		argv = command(argv);
		exec(argv, line);
	}
	return (0);
}
