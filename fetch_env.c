#include "shell.h"


/**
 * pt_env - writes environ to stdout.
 * @listx: arguments list
 *
 * Return: 0 on Success
 */

int pt_env(inventory_t *listx)
{
	list_t *envlist = listx->envlist;
	char **commd;

	commd = (char **)listx->commd;

	if (commd[1] != NULL)
	{
		_perror("env: No such file or directory\n");
		return (-1);
	}

	print_list(envlist);

	return (EXT_SUCCESS);
}

/**
 * print_list - prints all elements of linked list
 * @head: head of the linked list to be printed
 *
 * Return: number of nodes printed.
 */
size_t print_list(list_t *head)
{
	unsigned int i = 0;
	char **_environ;

	_environ = L_list_to_dptr(head);
	while (_environ[i])
	{
		_putz(_environ[i]);
		free(_environ[i]);
		i++;
	}

	free(_environ);
	return (i);
}


/**
 * add_node_end - it adds a new node at the end of a list_t list.
 * @head: double pointer which is the first pointing to list_t
 * @val: value to be added
 * @var: variable to be added
 * Return: pointer to new added node
 **/
list_t *add_node_end(list_t **head, char *var, char *val)
{
	list_t *newn;
	list_t *temp = *head;

	newn = safe_malloc(sizeof(list_t));

	if (newn == NULL)
		return (NULL);

	newn->val = _strdupp(val);
	newn->var = _strdupp(var);
	newn->next = NULL;

	if (*head == NULL)
	{
		*head = newn;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = newn;
	}
	return (newn);
}

/**
 * split_str - separates string at first plus
 * @str: one string from environ or alias input
 *
 * Return: array of 2 strings
 */
char **split_str(char *str)
{
	char **OUTcome, *left, *right;
	int i, j, lenleft = 0, lenright = 0;

	while (str[lenleft] != '=')
		lenleft++;
	left = safe_malloc(sizeof(char) * lenleft + 1);

	for (i = 0;  i < lenleft; i++)
		left[i] = str[i];

	i = lenleft + 1;

	while (str[i] != '\0')
		lenright++, i++;
	right = safe_malloc(sizeof(char) * lenright + 1);

	for (i = lenleft + 1, j = 0; j < lenright; i++, j++)
		right[j] = str[i];

	OUTcome = safe_malloc(sizeof(char *) * 3);
	OUTcome[0] = left, OUTcome[1] = right;

	return (OUTcome);
}
