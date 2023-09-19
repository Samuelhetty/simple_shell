#include "shell.h"

/**
* _putzar - brings the character to std output
* @c: the character to print out
*
* Return: on success 1
* on error, -1 is returned, and error is set appr.
*/
int _putzar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putz - outputs a string to standard output
 * @str: the string to be printed
 * Return: 0 on success
 */
int _putz(const char *str)
{
	if (str == NULL)
	{
		return (EOF);
	}
	while (*str != '\0')
	{
		_putzar(*str);
		str++;
	}
	_putzar('\n');

	return (0);
}

/**
 * _memcpy - copies information between void pointers.
 * @newptr: location of the pointer.
 * @ptr: source of the pointer.
 * @size: size of the generated pointer.
 *
 * Return: return zero.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}
