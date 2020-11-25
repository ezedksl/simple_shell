#include "shell.h"

/**
  * freeargv - Function to free argv (splitted tokens grid)
  * @argv: Splitted tokens double array
  * Return: void
  */
void freeargv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

