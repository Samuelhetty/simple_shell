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
