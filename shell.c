#include "shell.h"

/**
 * del_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *del_comment(char *in)
{
	int i, cont;

	cont = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				cont = i;
		}
	}
	if (cont != 0)
	{
		in = _realloc(in, i, cont + 1);
		in[cont] = '\0';
	}

	return (in);
}
/**
 * run_shell - process shell
 * @listx: argument list
 *
 * Return: no return.
 */
void run_shell(inventory_t *listx)
{
	int iterator, i_eof;
	char *N_commd;

	iterator = 1;
	while (iterator == 1)
	{
		write(STDIN_FILENO, "$ ", 2);
		N_commd = read_commd(&i_eof);
		if (i_eof != -1)
		{
			N_commd = del_comment(N_commd);
			if (N_commd == NULL)
				continue;

			if (handle_error(listx, N_commd) == 1)
			{
				listx->exit_status = 2;
				free(N_commd);
				continue;
			}
			N_commd = bash_replace(N_commd, listx);
			iterator = tokenize_cmmd(listx, N_commd);
			listx->commd_tally += 1;
			free(N_commd);
		}
		else
		{
			iterator = 0;
			free(N_commd);
		}
	}
}

/**
 * read_commd - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_commd(int *i_eof)
{
	char *N_commd = NULL;
	size_t buflimit = 0;

	*i_eof = getline(&N_commd, &buflimit, stdin);

	return (N_commd);
}
