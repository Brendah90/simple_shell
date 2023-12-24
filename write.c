#include "shell.h"

/**
 * _puts - prints string to stdout
 * @str: string to print
 *
 * Return: bytes printed
 */
int _puts(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _eputs - prints errors to stderr
 * @str: string to print
 *
 * Return: bytes printed
 */
int _eputs(char *str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}
