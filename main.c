#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: number of arguments passed to the program
 * @argv: list of arguments passed to the program
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	int pip_check = isatty(STDIN_FILENO);
	data_t info = DATA_INIT;

	info.argv = argv;
	(void)argc;
	errno = 0;
	while (1)
	{
		if (pip_check)
			write(STDOUT_FILENO, "$ ", 2);
		info.bytes = getline(&(info.buffer), &(info.buffer_length), stdin);
		if (info.bytes == -1)
		{
			free(info.buffer);
			break;
		}
		info.cmd_args = tokenize(info.buffer, " \t\n");
		if (info.cmd_args[0] == NULL)
		{
			free(info.cmd_args);
			continue;
		}

		if (is_builtin(info))
			continue;
		if (!check_cmd(info))
		{
			free(info.buffer);
			info.buffer = NULL;
			info.process_no += 1;
			errno = 127;
			continue;
		}
		execute(info);
		info.process_no += 1;
	}
	return (errno);
}
