#include "shell.h"
/**
 * read_textfile - reads a text file and prints
 * @filename: the name of the file
 * @letters: count to be printed
 * Return: the no of letters read and printed or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	ssize_t nrd, nwr;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);

	nrd = read(fd, buff, letters);
	nwr = write(STDOUT_FILENO, buff, nrd);

	close(fd);
	free(buff);

	return (nwr);
}

/**
 * create_file - a function that creates a file.
 * @filename: name of the file
 * @text_content: the content of the file
 * Return: 1 on success and -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int wrr;
	int num;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	for (num = 0; text_content[num]; num++)
		;

	wrr = write(fd, text_content, num);

	if (wrr == -1)
		return (-1);

	close(fd);

	return (1);
}

/**
 * append_text_to_file - appends text at the end
 * @filename: name of file for text append to
 * @text_content: text to append to the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int num;
	int wrr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (num = 0; text_content[num]; num++)
			;
		wrr = write(fd, text_content, num);
		if (wrr == -1)
			return (-1);
	}
	close(fd);

	return (1);
}
