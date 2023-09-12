#include "shell.h"

/**
 * free_list - function to free list
 * @head: the head of the list
 *
 */
void free_list(list_t **head)
{
	list_t *temp, *next;

	if (head != NULL)
	{
		temp = *head;
		while ((next = temp) != NULL)
		{
			temp = temp->next;
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
 */
void free_tok(tokens_t **head)
{
	tokens_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
/**
 * free_commd - frees allocated memory for struct cmmd_t
 *
 * @head: first node
 */
void free_commd(cmmd_t **head)
{
	cmmd_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->cmmd);
		free(temp);
	}
}
