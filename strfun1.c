#include "shell.h"

/**
 * _strncate - a function that appends a string
 * @dest: destination str
 * @src: source str
 * @n: unsigned integer
 * Return: a character
 */

char *_strncate(char *dest, char *src, int n)
{
	size_t dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = '\0';

	return (dest);
}
/**
 * hf_strtok - separets a string by some of delimite
 * @str: input str
 * @delim: delimiter
 *
 * Return: str separate
 */
char *hf_strtok(char str[], const char *delim)
{
	static char *split_tok, *lastTok;
	char *startTok;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (_stricomp(str, delim))
			return (NULL);
		split_tok = str; /*Store first address*/
		i = _strlen(str);
		lastTok = &str[i]; /*Store last address*/
	}
	startTok = split_tok;
	if (startTok == lastTok) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *split_tok; split_tok++)
	{
		/*Breaking loop finding the next token*/
		if (split_tok != startTok)
			if (*split_tok && *(split_tok - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*split_tok == delim[i])
			{
				*split_tok = '\0';
				if (split_tok == startTok)
					startTok++;
				break;
			}
		}
		if (bool == 0 && *split_tok) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (startTok);
}
