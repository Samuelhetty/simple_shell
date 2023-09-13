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
	struct stat begin;

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
				if (stat(id, &begin) == 0)
					return (id);
			len1 = _strlen(tok_path);
			directories = safe_malloc(len1 + len2 + 2);
			_strcpy(directories, tok_path);
			_strcate(directories, "/");
			_strcate(directories, id);
			_strcate(directories, "\0");
			if (stat(directories, &begin) == 0)
			{
				free(paths);
				return (directories);
			}
			free(directories);
			tok_path = hf_strtok(NULL, ":");
		}
		free(paths);
		if (stat(id, &begin) == 0)
			return (id);
		return (NULL);
	}
	if (id[0] == '/')
		if (stat(id, &begin) == 0)
			return (id);
	return (NULL);
}
