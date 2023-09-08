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
