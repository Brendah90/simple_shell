#include "shell.h"

/**
 * tokenize - splits string into tokens
 * @buffer: string to split
 * @delim: delimiter
 *
 * Return: Array of splitted parts terminated by a NULL pointer
 */
char **tokenize(char *buffer, char *delim)
{
	char *buf = NULL;
	char **parts = NULL;
	int i = 0;

	if (buffer == NULL)
	{
		return (NULL);
	}

	parts = malloc(sizeof(char *) * MAX_ARGS);
	if (parts == NULL)
	{
		return (NULL);
	}
	buf = strtok(buffer, delim);

	while (buf != NULL && i < MAX_ARGS - 1)
	{
		parts[i] = _strdup(buf);
		buf = strtok(NULL, delim);
		i++;
	}
	parts[i] = NULL;

	return (parts);
}
