#include "shell.h"

/**
  * tokenize - Receives a line as an input and
  * stores space separated tokens (strings)
  * @line: Line to be splitted
  * Return: Line splitted into tokens
  */

char **tokenize(char *line)
{

	char **words = malloc(sizeof(char *) * 32);
	char *token = NULL;
	int tkount = 0, toksize = 0, i;

	i = _strlen(line);
	line[i - 1] = '\0';
	token = strtok(line, " ");
	while (token != NULL)
	{
		toksize = _strlen(token);
		words[tkount] = malloc(toksize + 1);
		_strcpy(words[tkount], token);
		token = strtok(NULL, " ");
		tkount++;
	}
	words[tkount] = NULL;
	return (words);
}
