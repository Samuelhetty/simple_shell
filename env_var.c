#include "shell.h"

/**
 * perform_search - checks if the typed variable is an env variable
 *
 * @head: head of linked list
 * @input: input string
 * @envlist: env lists
 * Return: no return
 */
void perform_search(list_t **head, char *input, inventory_t *envlist)
{
	int left, right, j, len;
	char **env_list;

	env_list = envlist->_environ;
	for (left = 0; env_list[left]; left++)
	{
		for (j = 1, right = 0; env_list[left][right]; right++)
		{
			if (env_list[left][right] == '=')
			{
				len = _strlen(env_list[left] + right + 1);
				add_node_end(head, j, env_list[left] + right + 1, len);
				return;
			}
			if (input[j] == env_list[left][right])
				j++;
			else
				break;
		}
	}

	for (j = 0; input[j]; j++)
	{
		if (input[j] == ' ' || input[j] == '\t' ||
				input[j] == ';' || input[j]
				== '\n')
			break;
	}

	add_node_end(head, j, NULL, 0);
}
/**
 * identify_vars - identify the typed variable as $$ or $?
 *
 * @head: head of the linked list
 * @input: input string
 * @last_bg_status: last status of the Shell
 * @inventory: arg list
 * Return: no return
 */
int identify_vars(list_t **head, char *input, char *last_bg_status,
		inventory_t *inventory)
{
	int i, bg, pd;

	bg = _strlen(last_bg_status);
	pd = _strlen(inventory->pid);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '?')
				add_node_end(head, 2, last_bg_status, bg), i++;
			else if (input[i + 1] == '$')
				add_node_end(head, 2, inventory->pid, pd), i++;
			else if (input[i + 1] == '\n')
				add_node_end(head, 0, NULL, 0);
			else if (input[i + 1] == '\0')
				add_node_end(head, 0, NULL, 0);
			else if (input[i + 1] == ' ')
				add_node_end(head, 0, NULL, 0);
			else if (input[i + 1] == '\t')
				add_node_end(head, 0, NULL, 0);
			else if (input[i + 1] == ';')
				add_node_end(head, 0, NULL, 0);
			else
				perform_search(head, input + i, inventory);
		}
	}

	return (i);
}
/**
 * replaced_var - replaces string into variables
 *
 * @head: head of the linked list
 * @N_commd: input string
 * @N_input: new input string (replaced)
 * @N_len: new length
 * Return: replaced string
 */
char *replaced_var(list_t **head, char *N_commd, char *N_input, int N_len)
{
	list_t *count;
	int i, j, k;

	count = *head;
	for (j = i = 0; i < N_len; i++)
	{
		if (N_commd[j] == '$')
		{
			if (!(count->var) && !(count->val))
			{
				N_input[i] = N_commd[j];
				j++;
			}
			else if (count->var && !(count->val))
			{
				for (k = 0; k < count->var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < count->val; k++)
				{
					N_input[i] = count->val[k];
					i++;
				}
				j += (count->var);
				i--;
			}
			count = count->next;
		}
		else
		{
			N_input[i] = N_commd[j];
			j++;
		}
	}

	return (N_input);
}

/**
 * bash_replace - calls functions replace string
 *
 * @listx: list
 * @N_commd: argument lists
 *
 * Return: replaced string
 */
char *bash_replace(char *N_commd, inventory_t *listx)
{
	list_t *head, *count;
	char *exit_status, *N_input;
	int old, new;

	exit_status = int_to_str(listx->exit_status);
	head = NULL;

	old = identify_vars(&head, N_commd, exit_status, listx);

	if (head == NULL)
	{
		free(exit_status);
		return (N_commd);
	}

	count = head;
	new = 0;

	while (count != NULL)
	{
		new += (count->val - count->var);
		count = count->next;
	}

	new += old;

	N_input = safe_malloc(sizeof(char) * (new + 1));
	N_input[new] = '\0';

	N_input = replaced_var(&head, N_commd, N_input, new);

	free(N_commd);
	free(exit_status);
	free_list(&head);

	return (N_input);
}
