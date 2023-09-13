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
char *hf_strtok(char *str, const char *delim)
{
    static char *lastToken = NULL;
    char *token;
    bool foundDelimiter = false;

    /*If str is NULL, continue tokenizing from the last token's position*/
    if (str == NULL)
        str = lastToken;

    /* Skip leading delimiters*/
    while (*str != '\0' && strchr(delim, *str) != NULL)
        str++;

    /* If we've reached the end of the string or it's all delimiters, return NULL*/
    if (*str == '\0')
        return NULL;

    /* Find the end of the token (next delimiter or end of string)*/
    token = str;
    while (*str != '\0' && strchr(delim, *str) == NULL)
        str++;

    /* If we found a delimiter, null-terminate the token and update lastToken*/
    if (*str != '\0') {
        *str = '\0';
        str++;
        foundDelimiter = true;
    }

    /* Update lastToken if a delimiter was found, otherwise set it to NULL*/
    lastToken = foundDelimiter ? str : NULL;

    return token;
}
