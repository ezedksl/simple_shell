#include "shell.h"

/**
 * command - entry point
 * @words: arguments passed to the function
 * Return: words
 */

char **command(char **words)
{
	char *path = NULL, *token = NULL, *concat = NULL;
	struct stat st;
	int size = 0;

	if (stat(words[0], &st) == 0)
		return (words);
	path = _getenv("PATH");
	token = strtok(path, ":");
	while (token)
	{
		if (stat(concat, &st) == 0)
		{
			free(words[0]);
			size = _strlen(concat);
			words[0] = malloc(sizeof(char) * size + 1);
			if (words[0] == NULL)
			{
				free(words[0]);
				return (NULL);
			}
			words[0] = _strcpy(words[0], concat);
			free(concat);
			free(path);
			return (words);
		}
		else
		{
			token = strtok(NULL, ":");
			free(concat);
		}
	}
	free(path);
	return (words);
}

/**
  * concatenar - Concatenate path token and command to save into the argv0
  * @concat: string
  * @words: double array
  * @token: current path token
  * Return: concatenated string
  */

char *concatenar(char *concat, char **words, char *token)
{
	int size;

	size = _strlen(words[0]) + _strlen(token);
	concat = malloc(sizeof(char) * (size + 2));
	if (concat == NULL)
	{
		free(concat);
		return (NULL);
	}
	concat = _strcpy(concat, token);
	concat = _strcat(concat, "/");
	concat = _strcat(concat, words[0]);
	return (concat);
}
