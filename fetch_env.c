#include "shell.h"

/**
 * check_ID - compares env variables names
 * with the name passed.
 * @n_var: name of the environment variable
 * @ID: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int check_ID(const char *n_var, const char *ID)
{
	int i;

	for (i = 0; n_var[i] != '='; i++)
	{
		if (n_var[i] != ID[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * pt_env - writes environ to stdout.
 * @listx: arguments list
 *
 * Return: 1 on Success
 */

int pt_env(inventory_t *listx)
{
	int i, j;

	for (i = 0; listx->_environ[i]; i++)
	{

		for (j = 0; listx->_environ[i][j]; j++)

			write(STDOUT_FILENO, listx->_environ[i], j);
		write(STDOUT_FILENO, "n", 1);
	}
	listx->exit_status = 0;

	return (1);
}

/**
 * print_list - prints environmental variable list
 * @ID: name of the environment variable
 * @_environ: env variables
 *
 * Return:  value of the environment variable if is found.
 * In other case, returns NULL
 */
char print_list(const char *ID, char **_environ)
{
	char *_env;
	int i, nxt;

	/* Initialize _env value */
	_env = NULL;
	nxt = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		nxt = check_ID(_environ[i], ID);
		if (nxt)
		{
			_env = _environ[i];
			break;
		}
	}
	return (_env + nxt);
}


/**
 * add_node_end - it adds a new node at the end of a list_t list.
 * @head: double pointer which is the first pointing to list_t
 * @val: value lenght
 * @value: value of variable
 * @var: variable lenght
 * Return: pointer to new added node
 **/
list_t *add_node_end(list_t **head, int var, char *value, int val)
{
	/*Create a new node*/
	list_t *newn, *temp;

	newn = safe_malloc(sizeof(list_t));

	/*Check if memory allocation failed*/
	if (newn == NULL)
	{
		_perror("Memory allocation failed\n");
		exit(EXT_FAILURE);
	}

	/*Fill in the base node's values*/
	newn->value = value;
	newn->var = var;
	newn->val = val;

	/*Set the function pointer to NULL initially*/
	newn->next = NULL;
	temp = *head;

	/*If the list is empty, set the new node as the head*/
	if (*temp == NULL)
	{
		*head = newn;
	}
	else
	{
		/*Otherwise, traverse the list and add the new_node to the end*/
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newn;
	}

	return (newn);
}
