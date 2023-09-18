#include "shell.h"

/**
 * run_builtin - builtin that pass the command in the arg
 * @id: command
 * Return: function pointer of the builtin command
 */
int (*run_builtin(char *id))(inventory_t *)
{
	int tally;

	builtins_t builtin_list[] = {
		{ "env", pt_env }, { "exit", ezit },
		{ "help", pt_help }, { NULL, NULL }
	};

	for (tally = 0; builtin_list[tally].args; tally++)
	{
		if (hf_strcmp(builtin_list[tally].args, id) == 0)
			break;
	}

	return (builtin_list[tally].builtin_func);
}

/**
 * processor_builtins -custom function to execute builtin commands
 * @listx: argument list
 *
 * Return: 1 on success. 0 on failure
 **/

int processor_builtins(inventory_t *listx)
{
	int (*builtin_list)(inventory_t *listx);

	if (listx->envlist[0] == NULL)
		return (1);

	builtin_list = run_builtin(listx->envlist[0]);

	if (builtin_list != NULL)
		return (builtin_list(listx));

	return (execute(listx));
}

/**
 * pt_help - function that retrieves help messages according builtin
 * @listx: inventory list
 * Return: Return 0
*/
int pt_help(inventory_t *listx)
{

	if (listx->envlist[1] == 0)
		help_all();
	else if (_stricomp(listx->envlist[1], "env") == 0)
		h_env();
	else if (_stricomp(listx->envlist[1], "help") == 0)
		hf_help();
	else if (_stricomp(listx->envlist[1], "exit") == 0)
		h_exit();
	else
		write(STDERR_FILENO, listx->envlist[0],
				_strlen(listx->envlist[0]));

	listx->exit_status = 0;
	return (1);
}
