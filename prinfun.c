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
