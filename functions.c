#include "shell.h"
/**
 * hf_strtok - tokenize (split) a string into smaller parts
 * @str: the string to split
 * @delim: on a specified delimiter
 * Return: a char
 */
char *hf_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_end;

	if (str != NULL)
	{
		next_token = str;
	}
	else if (next_token == NULL)
	{
		return (NULL);
	}

	next_token += strspn(next_token, delim);

	if (*next_token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}

	token_end = next_token + strcspn(next_token, delim);

	if (*token_end != '\0')
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
	{
		next_token = NULL;
	}

	return (next_token);
}
/**
 * ezit - a function that terminates the program
 */
void ezit(void)
{
	exit(0);
}

/**
 * hf_print - prints char to stdout
 * @prints: string to be printed
 *
 * Return: void
 */
void hf_print(const char *prints)
{
	write(STDOUT_FILENO, prints, _strlen(prints));
}
