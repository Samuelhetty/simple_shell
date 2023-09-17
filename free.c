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
