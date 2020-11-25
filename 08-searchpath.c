#include "shell.h"

/**
 * command - entry point
 * @argv: arguments passed to the function
 * Return: argv
 */

char **command(char **argv)
{
	char *path = NULL, *token = NULL, *concat = NULL;
	struct stat st;
	int sizeargv = 0, sizetokpath = 0, size = 0;

	if (stat(argv[0], &st) == 0)
		return (argv);
	path = _getenv("PATH");
	token = strtok(path, ":");
	while (token)
	{
		size = _strlen(argv[0] + _strlen(token));
		concat = malloc(sizeof(char) * (size + 2));
		if (concat == NULL)
		{
			free(concat);
			return (NULL);
		}
		concat = _strcpy(concat, token);
		concat = _strcat(concat, "/");
		concat = _strcat(concat, argv[0]);
		if (stat(concat, &st) == 0)
		{
			free(argv[0]);
			size = _strlen(concat);
			argv[0] = malloc(sizeof(char) * size + 1);
			if (argv[0] == NULL)
			{
				free(argv[0]);
				return (NULL);
			}
			argv[0] = _strcpy(argv[0], concat);
			free(concat);
			free(path);
			return (argv);
		}
		token = strtok(NULL, ":");
		free(concat);
	}
	free(path);
	return (argv);
}
