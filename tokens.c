#include "shell.h"

/**
 * tokenize - tokenizes the input string
 *
 * @N_commd: input string.
 * Return: string splitted.
 */
char **tokenize(char *N_commd)
{
	size_t buflimit;
	size_t i;
	char **tokenN;
	char *split;

	buflimit = TOK_BUFSIZE;
	tokenN = malloc(sizeof(char *) * (buflimit));
	if (tokenN == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXT_FAILURE);
	}
	split = hf_strtok(N_commd, TOK_DELIMIT);
	tokenN[0] = split;

	for (i = 1; split != NULL; i++)
	{
		if (i == buflimit)
		{
			buflimit += TOK_BUFSIZE;
			tokenN = dptr_alloc(tokenN, i, sizeof(char *) * buflimit);
			if (tokenN == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXT_FAILURE);
			}
		}
		split = hf_strtok(NULL, TOK_DELIMIT);
		tokenN[i] = split;
	}

	return (tokenN);
}
/**
 * add_tok_node_end - adds a node to token list
 *
 * @head: first node
 * @div: seperator
 * Return: located head
 */
tokens_t *add_tok_node_end(tokens_t **head, char div)
{
	tokens_t *N_node, *temp;

	N_node = malloc(sizeof(tokens_t));
	if (N_node == NULL)
		return (NULL);

	N_node->tokens = div;
	N_node->next = NULL;
	temp = *head;

	if (head == NULL)
	{
		*head = N_node;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = N_node;
	}
	return (*head);
}
/**
 * add_cmmd_node_end - adds a command node at end of the list
 *
 * @head: first node
 * @cmmd: command
 * Return: located head
 */
cmmd_t *add_cmmd_node_end(cmmd_t **head, char *cmmd)
{
	cmmd_t *N_node, *temp;

	N_node = malloc(sizeof(cmmd_t));
	if (N_node == NULL)
		return (NULL);

	N_node->cmmd = cmmd;
	N_node->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = N_node;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = N_node;
	}

	return (*head);
}
