#include "shell.h"

/**
 * link_tally - counts number of nodes in linked list
 * @head: pointer to head of linked list
 *
 * Return: number of nodes
 */
unsigned int link_tally(list_t *head)
{
	list_t *tmp;
	unsigned int tally;

	tmp = head;
	tally = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		tally++;
	}
	return (tally);
}

/**
 * env_list - creates a linked list of all environ variables
 *
 * Return: head (pointer to first node of linked list of environ variables)
 */
list_t *env_list(void)
{
	int i = 0;
	list_t *head;
	char **var;

	head = NULL;
	for (; environ[i] != NULL; i++)
	{
		var = split_str(environ[i]);
		if (add_node_end(&head, var[0], var[1]) == NULL)
			return (NULL);
		free(var[0]);
		free(var[1]);
		free(var);
	}
	return (head);
}
/**
 * L_list_to_dptr - converts linked list to double pointer
 * @head: head pointer to head of linked list
 *
 * Return: array of pointers, pointing to strings
 */
char **L_list_to_dptr(list_t *head)
{
	int i;
	unsigned int tally, len1, len2, N_len;
	char **dptr, *var, *val, *N_val;
	list_t *tmp;

	tally = link_tally(head);
	dptr = safe_malloc(sizeof(char *) * (tally + 1));
	tmp = head;
       	i = 0;

	while (tmp != NULL)
	{
		var = tmp->var;
		val = tmp->val;
		len1 = _strlen(var);
		len2 = _strlen(val);
		N_len = len1 + len2 + 2;
		N_val = safe_malloc(N_len * sizeof(char));

		_strncate(N_val, var, len1);
		_strncate(N_val, "=", 1);
		_strncate(N_val, val, len2);
		dptr[i] = N_val;
		tmp = tmp->next;
		i++;
	}
	dptr[i] = NULL;

	return (dptr);
}

/**
 * free_env - function to free all allocated memory
 * @head: pointer to a pointer to the head of the list
 *
 * Return: 0 on success, 1 on failure
 */
int free_env(list_t *head)
{
	list_t *temp = head;

	while (head)
	{
		temp = temp->next;
		free(head->var);
		free(head->val);
		free(head);
		head = temp;
	}
	return (EXT_SUCCESS);
}

/**
 * fetch_node - fetches a node of a given var
 * @head: head of list
 * @var: value to match of the node to fetch
 *
 * Return: fetched node or head
 */
list_t *fetch_node(list_t *head, char *var)
{
	list_t *tmp;

	tmp = head;

	while (tmp != NULL)
	{
		if (_stricomp(tmp->var, var) == 0)
			return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}
