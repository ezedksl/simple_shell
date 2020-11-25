#include "shell.h"

/**
 * command - entry point
 * @words: arguments passed to the function
 * Return: words
 */

char **command(char **words)
{
	struct stat st;
	char *path = NULL;

	if (stat(words[0], &st) == 0)
		return (words);
	path = _getenv("PATH");
	words = tokpath(words, path);
	return (words);
}
