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
 * ezit - exit status to exit
 * @listx: arguments inventory
 *
 * Return: 0 on success
 */
int ezit(inventory_t *listx)
{
	char **envlist;
	int e_status;

	envlist = (char **)listx->envlist;
	if (envlist[1] == NULL)
		listx->exit = 1;
	else if (is_unsignedint(envlist[1]))
	{
		e_status = _atoi(envlist[1]);
		listx->exit = 1;
		listx->exit_status = e_status;
	}
	else
		_perror("exit: Illegal number\n");

	return (EXT_SUCCESS);
}


/**
 * is_unsignedint - checks if input string is unsigned int
 * @num: the input number
 * Return: TRUE or FALSE
 */
int is_unsignedint(char *num)
{
	int i = 0;

	while (num[i])
	{
		if (num[i] > 47 && num[i] < 58)
			i++;
		else if (num[i] == 45 && i == 0)
			return (FALSE);
		else
			return (FALSE);
	}

	return (TRUE);
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
