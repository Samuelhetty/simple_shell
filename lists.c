/**
 * buildarginv - Initialize arguments
 *
 * @listx: arguments list
 * @av: argument vector
 * Return: no return
 */
void buildarginv(inventory_t *listx, char **av)
{
        unsigned int i;

        listx->av = av;
        listx->N_commd = NULL;
	listx->st_mode = _filemode(STDIN_FILENO);
        listx->args = NULL;
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
        listx->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	inventory_t listx;
	(void) ac;

	signal(SIGINT, display_prompt);
	buildarginv(&listx, av);
	run_shell(&listx);
	free_list(&listx);
	if (listx.exit_status < 0)
		return (255);
	return (listx.exit_status);
}