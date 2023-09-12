#include "shell.h"
/**
 * _strcpy - copies the string pointed to by src
 *
 * @dest: string one pointer to a char
 * @src: string two pointer to a char
 * Return: character (dest)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * ezit - a function that terminates the program
 * @exit: exit the program successfully
 */
void ezit(int exit)
{
	exit(exit);
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
