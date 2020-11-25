#include "shell.h"

/**
 * linecheck - entry point
 * @line: line
 * Return: always 0
 */


int linecheck(char *line)
{
	if (line[0] == '\n')
	{
		free(line);
		return ('\n');
	}
	if (_strcmp(line, "exit\n") == 0)
	{
		free(line);
		return (-1);
	}
	if (_strcmp(line, "env\n") == 0)
	{
		_printenv();
		free(line);
		return (1);
	}
	return (0);
}
