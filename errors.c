#include "shell.h"

/**
 * _print_error - prints errors to stdin
 * @info: a struct with program info
 */
void _print_error(data_t info)
{
	char process[4];

	num_to_string(process, info.process_no);
	_eputs(info.argv[0]);
	_eputs(": ");
	_eputs(process);
	_eputs(": ");
	_eputs(info.argv[0]);
	_eputs(": not found\n");
}

/**
 * _print_atoi_error - prints errors to stdin
 * @info: a struct with program info
 */
void _print_atoi_error(data_t info)
{
	char process[4];

	num_to_string(process, info.process_no);
	_eputs(info.argv[0]);
	_eputs(": ");
	_eputs(process);
	_eputs(": ");
	_eputs(info.cmd_args[0]);
	_eputs(": Illegal number: ");
	_eputs(info.cmd_args[1]);
	_eputs("\n");
}
