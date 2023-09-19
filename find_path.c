#include "shell.h"


/**
 * ch_dir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int ch_dir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}
/**
 * locate_path - locates a command
 *
 * @id: command name
 * @_environ: environment variable
 * Return: location of the command.
 */
char *locate_path(char *id, char **_environ)
{
	char *path, *paths, *tok_path, *directories;
	int len1, len2, i;
	struct stat st;

	path = print_var("PATH", _environ);
	if (path)
	{
		paths = _strdupp(path);
		len2 = _strlen(id);
		tok_path = hf_strtok(paths, ":");
		i = 0;
		while (tok_path != NULL)
		{
			if (ch_dir(path, &i))
				if (stat(id, &st) == 0)
					return (id);
			len1 = _strlen(tok_path);
			directories = safe_malloc(len1 + len2 + 2);
			_strcpy(directories, tok_path);
			_strcate(directories, "/");
			_strcate(directories, id);
			_strcate(directories, "\0");
			if (stat(directories, &st) == 0)
			{
				free(paths);
				return (directories);
			}
			free(directories);
			tok_path = hf_strtok(NULL, ":");
		}
		free(paths);
		if (stat(id, &st) == 0)
			return (id);
		return (NULL);
	}
	if (id[0] == '/')
		if (stat(id, &st) == 0)
			return (id);
	return (NULL);
}
/**
 * exec_path - determines if is an executable
 *
 * @listx: argument inventory
 * Return: 0 not an executable, other number if it does
 */
int exec_path(inventory_t *listx)
{
	struct stat st;
	int i;
	char *N_commd;

	N_commd = listx->envlist[0];

	for (i = 0; N_commd[i]; i++)
	{
		if (N_commd[i] == '.')
		{
			if (N_commd[i + 1] == '.')
				return (0);
			if (N_commd[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (N_commd[i] == '/' && i != 0)
		{
			if (N_commd[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);
	if (stat(N_commd + i, &st) == 0)
	{
		return (i);
	}
	process_error(listx, 127);
	return (-1);
}
/**
 * find_error - verifies if user has permissions to access
 *
 * @directories: destination directory
 * @listx: argument list
 * Return: 1 if there is an error, 0 if not
 */
int find_error(char *directories, inventory_t *listx)
{
	if (directories == NULL)
	{
		process_error(listx, 127);
		return (1);
	}


	if (hf_strcmp(listx->envlist[0], directories) != 0)
	{
		if (access(directories, X_OK) == -1)
		{
			process_error(listx, 126);
			free(directories);
			return (1);
		}
		free(directories);
	}
	else
	{
		if (access(listx->envlist[0], X_OK) == -1)
		{
			process_error(listx, 126);
			return (1);
		}
	}

	return (0);
}
/**
 * execute - executes command lines
 *
 * @listx: argument inventory
 * Return: 1 on success.
 */
int execute(inventory_t *listx)
{
	pid_t pd, waitpd;
	int state;
	int exe;
	char *directories;
	(void) waitpd;

	exe = exec_path(listx);

	if (exe == -1)
		return (1);
	if (exe == 0)
	{
		directories = locate_path(listx->envlist[0], listx->_environ);
		if (find_error(directories, listx) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exe == 0)
			directories = locate_path(listx->envlist[0], listx->_environ);
		else
			directories = listx->envlist[0];

		execve(directories + exe, listx->envlist, listx->_environ);
	}
	else if (pd < 0)
	{
		_perror(listx->argv[0]);
		return (1);
	}
	else
	{
		do {
			waitpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	listx->exit_status = state / 256;
	return (1);
}
