#include "shell.h"

/**
* _getline - custom getline currently reads 1 char at a time
* @buffer: address of pointer to input commands buffer
* @LTD: maxsize of input character string, realloc if necessary
*
* Return: number of characters written
*/
ssize_t _getline(char **buffer, size_t *LTD)
{
	ssize_t tally;

	tally = _readline(STDIN_FILENO, buffer, LTD);

	return (tally);
}
/**
* _readline - custom getline currently reads 1 char at a time from a file
* descriptor
* @fd: file descriptor of the file to use for reading
* @buffer: address of pointer to input commands buffer
* @LTD: maxsize of input character string, realloc if necessary
*
* Return: number of characters written
*/
ssize_t _readline(int fd, char **buffer, size_t *LTD)
{
	unsigned int i, j;
	size_t ch_stat, iterations;

	ch_stat = 0;

	iterations = 1;
	j = 0;
	i = -1;

	while (i != 0)
	{
		i = read(fd, (*buffer + j), 1);

		if (i <= 0)
			break;

		ch_stat++;

		if ((*buffer + j++)[0] == '\n')
			break;

		if (ch_stat % *LTD == 0)
		{
			iterations++;

			*buffer = _realloc(*buffer, ch_stat, (*LTD * iterations));
		}
	}
	return ((ssize_t)ch_stat);
}
