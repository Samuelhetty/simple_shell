#include "shell.h"

/**
 * tokenize - tokenizes the input string
 *
 * @N_commd: input string.
 * Return: string splitted.
 */
char **tokenize(char *N_commd)
{
	size_t bsize;
	size_t i;
	char **tokenN;
	char *split;

	bsize = TOK_BUFSIZE;
	tokenN = safe_malloc(sizeof(char *) * (bsize));
	if (tokenN == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXT_FAILURE);
	}
	split = hf_strtok(N_commd, TOK_DELIMIT);
	tokenN[0] = split;

	for (i = 1; split != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokenN = _realloc(tokenN, i, sizeof(char *) * bsize);
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
 * @tokens: seperators
 *
 */
void add_tok_node_end(tokens_t **head, char tokens)
{
	tokens_t *N_node, *temp;

	N_node = safe_malloc(sizeof(tokens_t));
	N_node->tokens = tokens;
	N_node->next = NULL;

	if (*head == NULL)
	{
		*head = N_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = N_node;
	}
}
/**
 * add_cmmd_node_end - adds a command node at the end of the list
 *
 * @head: first node
 * @cmmd: command
 *
 */
void add_cmmd_node_end(cmmd_t **head, char *cmmd)
{
        cmmd_t *N_node, *temp;

        N_node = safe_malloc(sizeof(cmmd_t));
        N_node->cmmd = cmmd;
        N_node->next = NULL;

        if (*head == NULL)
        {
                *head = N_node;
        }
        else
        {
                temp = *head;
                while (temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = N_node;
        }
}
