#include "shell"


/**
 * ex_char - exchanges | and & for non-printed chars
 *
 * @N_commd: input string
 * @bool: type of exchange
 * Return: exchanged string
 */
char *ex_char(char *N_commd, int bool)
{
	int index;

	if (bool == 0)
	{
		for (index = 0; N_commd[index]; index++)
		{
			if (N_commd[index] == '|')
			{
				if (N_commd[index + 1] != '|')
					N_commd[index] = 16;
				else
					index++;
			}

			if (N_commd[index] == '&')
			{
				if (N_commd[index + 1] != '&')
					N_commd[index] = 12;
				else
					index++;
			}
		}
	}
	else
	{
		for (index = 0; N_commd[index]; index++)
		{
			N_commd[index] = (N_commd[index] == 16 ? '|' : N_commd[index]);
			N_commd[index] = (N_commd[index] == 12 ? '&' : N_commd[index]);
		}
	}
	return (N_commd);
}
/**
 * add_nodes - add separators and command lines in the lists
 *
 * @h1: head of separator list
 * @h2: head of command lines list
 * @N_commd: input string
e* Return: no return
 */
void add_nodes(token_s **h1, cmmd_s **h2, char *N_commd)
{
	int i;
	char *cmmd;

	N_commd = ex_char(N_commd, 0);

	for (i = 0; N_commd[i]; i++)
	{
		if (N_commd[i] == ';')
			add_tok_node_end(h1, N_commd[i]);

		if (N_commd[i] == '|' || N_commd[i] == '&')
		{
			add_tok_node_end(h1, N_commd[i]);
			i++;
		}
	}

	cmmd = _strtok(N_commd, ";|&");
	do {
		cmmd = ex_char(cmmd, 1);
		add_cmmd_node_end(h2, cmmd);
		cmmd = _strtok(NULL, ";|&");
	} while (cmmd != NULL);

}

/**
 * fetch_commd - fetches the next command line stored
 *
 * @tok_list: tokens list
 * @cmmd_list: command line list
 * @listx: arguments list
 * Return: no return
 */
void fetch_commd(token_t **tok_list, cmmd_t **cmmd_list, inventory_t *listx)
{
	int num_tok;
	token_t *temp1;
	cmmd_t *temp2;

	num_tok = 1;
	temp1 = *tok_list;
	temp2 = *cmmd_list;

	while (temp1 != NULL && num_tok)
	{
		if (listx->exit_status == 0)
		{
			if (temp1->tokens == '&' || temp1->tokens == ';')
				num_tok = 0;
			if (temp1->tokens == '|')
				temp2 = temp2->next, temp1 = temp1->next;
		}
		else
		{
			if (temp1->tokens == '|' || temp1->tokens == ';')
				num_tok = 0;
			if (temp1->tokens == '&')
				temp2 = temp2->next, temp1 = temp1->next;
		}
		if (temp1 != NULL && !num_tok)
			temp1 = temp1->next;
	}

	*tok_list = temp1;
	*cmmd_list = temp2;
}
/**
 * tokenize_cmmd - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @listx: arguments
 * @N_commd: input string
 * Return: 0 to exit, 1 to continue
 */
int tokenize_cmmd(inventory_t *listx, char *N_commd)
{
	token_t *h1, *tok_list;
	cmmd_t *h2, *cmmd_list;
	int iterate;

	h1 = NULL;
	h2 = NULL;

	add_nodes(&h1, &h2, N_commd);

	tok_list = h1;
	cmmd_list = h2;

	while (cmmd_list != NULL)
	{
		listx->N_commd = cmmd_list->cmmd;
		listx->envlist = split_line(listx->N_commd);
		iterate = exec_cmmd(listx);
		free(listx->envlist);

		if (iterate == 0)
			break;

		fetch_commd(&tok_list, &cmmd_list, listx);

		if (cmmd_list != NULL)
			cmmd_list = cmmd_list->next;
	}

	free_tok(&h1);
	free_cmmd(&h2);

	if (iterate == 0)
		return (0);
	return (1);
}
