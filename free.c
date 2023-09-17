#include "shell.h"

/**
 * free_list - function to free list
 * @head: the head of the list
 *
 */
void free_list(list_t **head)
{
	list_t *temp, *dis;

	if (head != NULL)
	{
		dis = *head;
		while ((temp = dis) != NULL)
		{
			dis = dis->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * free_cmmd - frees inventory
 *
 * @listx: argument list
 * Return: no return
 */
void free_cmmd(inventory_t *listx)
{
	unsigned int i;

	for (i = 0; listx->_environ[i]; i++)
	{
		free(listx->_environ[i]);
	}

	free(listx->_environ);
	free(listx->pid);
}
/**
 * free_tok - frees allocated memory for the struct tokens_t
 *
 * @head: first node
 * Return: 0 always
 */
void free_tok(tokens_t **head)
{
	tokens_t *dis, *temp;

	if (head != NULL)
	{
		dis = *head;
		while ((temp = dis) != NULL)
		{
		       dis = dis->next;
		       free(temp);
		}
		*head = NULL;
	}
}
/**
 * free_commd - frees allocated memory for struct cmmd_t
 *
 * @head: first node
 * Return: 0 always
 */
void free_commd(cmmd_t **head)
{
	cmmd_t *dis, *temp;

	if (head != NULL)
	{
		dis = *head;
		while ((temp = dis) != NULL)
		{
			dis = dis->next;
			free(temp);
		}
		*head = NULL;
	}
}
/**
 * handle_error - mid function to allocate and print a syntax error
 * @listx: inventory list
 * @N_commd: input string
 * Return: 1 if there is an error and 0 in other occasin
 */
int handle_error(inventory_t *listx, char *N_commd)
{
	int start, first_ch, i = 0;

	first_ch = char_entry(N_commd, &start);

	if (first_ch == -1)
	{
		pt_error(listx, N_commd, start, 0);
		return (1);
	}

	i = fetch_err(N_commd + start, 0, *(N_commd + start));

	if (i != 0)
	{
		pt_error(listx, N_commd, start + i, 1);
		return (1);
	}

	return (0);
}
