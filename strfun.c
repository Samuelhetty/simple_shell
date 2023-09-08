#include "shell.h"

/**
 *  _strcate - function that concatenates two strings
 *  @dest: entered value
 *  @src: entered value
 *
 *  Return: void
 */
char *_strcate(char *dest, char *src)
{
		int a;

		int b;

		a = 0;

		while (dest[a] != '\0')
		{
			a++;
		}
		b = 0;

		while (src[b] != '\0')
		{
			dest[a] = src[b];
			a++;
			b++;
		}
		dest[a] = '\0';
		return (dest);
}

/**
 * _strdupp -  returns a pointer to a new string, a duplicate
 * @str: the original string
 * Return: NUlL if pointer is NULL, or ponter to new string
 */
char *_strdupp(char *str)
{
	char *aaa;
	int i, r = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;

	while (str[i] != '\0')
		i++;

	aaa = malloc(sizeof(char) * (i + 1));

	if (aaa == NULL)
	{
		return (NULL);
	}

	for (r = 0; str[r]; r++)
	{
		aaa[r] = str[r];
	}

	return (aaa);
}

/**
 * _stricomp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _stricomp(char *s1, char *s2)
{
		int i;

		i = 0;
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
			{
				return (s1[i] - s2[i]);
			}
			i++;
		}
		return (0);
}
/**
 * _strlen - returns string length of input string
 * @s: string to check length of
 * Return: length of string
 */
size_t __attribute__ ((warn_unused_result)) _strlen(const char *s)
{
	size_t longi = 0;
	while (*s++)
	{
		longi++;
	}
	return (longi);
}
