#include "shell.h"

/**
 * display_prompt - a function that creates a prompt
 * @signa: an integer
 *
 * Return: nothing
 */

void display_prompt(int signa)
{
	(void) signa;
	_putz("");

	/*this will display thr prompt*/
	write(STDOUT_FILENO, "$  ", 2);
}

/**
 * _filemode - finds file mode of standard input
 * @fd: STDIN_FILENO
 *
 * Return: 1 a device like a terminal, 0 a FIFO special file, or a pipe
 */
int _filemode(int fd)
{
	int result = -1;
	struct stat buf;

	fstat(fd, &buf);

	switch (buf.st_mode & S_IFMT)
	{
		case S_IFCHR:
			result = 1;
			break;
		case S_IFIFO:
			result = 0;
			break;
		default:
			break;
	}

	return (result);
}
