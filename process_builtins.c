#include "shell.h"

/**
 * run_builtin - builtin that pass the command in the arg
 * @command: command
 * Return: function pointer of the builtin command
 */
int (*run_builtin(char *command))(inventory_t *)
{
	int tally;

	builtins_t builtin_list[] = {
		{ "env", pt_env }, { "exit", ezit },
		{ NULL, NULL }
	};

	for (tally = 0; builtin_list[tally].args; tally++)
	{
		if (_stricomp(builtin_list[tally].args, command) == 0)
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
	int (*builtin)(inventory_t *listx);

	if (listx->envlist[0] == NULL)
		return (1);

	builtin = run_builtin(listx->envlist[0]);

	if (builtin != NULL)
		return (builtin(listx));

	return (execute(listx));
}
