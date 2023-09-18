#include "shell.h"

/**
 * buildarginv - Initialize argument
 *
 * @listx: arguments list
 * @argv: argument vector
 */
void buildarginv(inventory_t *listx, char **argv)
{
	unsigned int i;

	listx->argv = argv;
	listx->N_commd = NULL;
	listx->envlist = NULL;
	listx->exit_status = 0;
	listx->commd_tally = 1;

	for (i = 0; environ[i]; i++)
		;

	listx->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		listx->_environ[i] = _strdupp(environ[i]);
	}

	listx->_environ[i] = NULL;
	listx->pid = int_to_str(getpid());
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	inventory_t listx;
	(void) argc;

	signal(SIGINT, display_prompt);
	buildarginv(&listx, argv);
	run_shell(&listx);
	free_cmmd(&listx);
	if (listx.exit_status < 0)
		return (255);
	return (listx.exit_status);
}
