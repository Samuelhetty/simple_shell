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
		{ "help", pt_help }, { NULL, NULL }
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
