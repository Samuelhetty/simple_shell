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
	char *new;
	size_t len;

	len = _strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, str, len + 1);
	return (new);
}
/**
 * hf_strcmp - compare string values
 * @s1: string1
 * @s2: string2
 *
 * Return: 0 always
 */
int hf_strcmp(char *s1, char *s2)
{
	int aaa;

	for (aaa = 0; s1[aaa] == s2[aaa] && s1[aaa]; aaa++)
		;

	if (s1[aaa] > s2[aaa])
		return (1);
	if (s1[aaa] < s2[aaa])
		return (-1);
	return (0);
}

/**
 * _stricomp - compare string values
 * @str: input value
 * @delim: delimiter
 *
 * Return: 1 if is = 0, if not
 */
int _stricomp(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
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
