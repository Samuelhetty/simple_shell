#include "shell.h"

/**
 * set_info - copies info to create
 * a new env or alias
 * @args: name (env or alias)
 * @eval: value (env or alias)
 *
 * Return: new env or alias.
 */
char *set_info(char *args, char *eval)
{
        char *n;
        int l_name, l_value, len;

        l_name = _strlen(args);
        l_value = _strlen(eval);
        len = l_name + l_value + 2;
        n = malloc(sizeof(char) * (len));
        _strcpy(n, args);
        _strcate(n, "=");
        _strcate(n, eval);
        _strcate(n, "\0");

        return (n);
}
/**
 * get_env - sets an environment variable
 *
 * @args: name of the environment variable
 * @eval: value of the environment variable
 * @listx: arg list
 * Return: no return
 */
void get_env(char *args, char *eval, inventory_t *listx)
{
        int i;
        char *var_env, *name_env;

        for (i = 0; listx->_environ[i]; i++)
        {
                var_env = _strdupp(listx->_environ[i]);
                name_env = hf_strtok(var_env, "=");
                if (hf_strcmp(name_env, args) == 0)
                {
                        free(listx->_environ[i]);
                        listx->_environ[i] = set_info(name_env, eval);
                        free(var_env);
                        return;
                }
                free(var_env);
        }

        listx->_environ = dptr_alloc(listx->_environ, i, sizeof(char *) * (i + 2));
        listx->_environ[i] = set_info(args, eval);
        listx->_environ[i + 1] = NULL;
}


/**
 * _setenv - compares env variables names
 * with the name passed.
 * @listx: inventory list
 *
 * Return: 1 on success.
 */
int _setenv(inventory_t *listx)
{

        if (listx->envlist[1] == NULL || listx->envlist[2] == NULL)
        {
                process_error(listx, -1);
                return (1);
        }

        get_env(listx->envlist[1], listx->envlist[2], listx);

        return (1);
}


/**
 * _unsetenv - deletes a environment variable
 *
 * @listx: inventory list
 *
 * Return: 1 on success.
 */
int _unsetenv(inventory_t *listx)
{
        char **realloc_environ;
        char *var_env, *name_env;

        int i, j, k;

        if (listx->envlist[1] == NULL)
        {
                process_error(listx, -1);
                return (1);
        }
        k = -1;
        for (i = 0; listx->_environ[i]; i++)
        {
                var_env = _strdupp(listx->_environ[i]);
                name_env = hf_strtok(var_env, "=");
                if (hf_strcmp(name_env, listx->envlist[1]) == 0)
                {
                        k = i;
                }
                free(var_env);
        }
        if (k == -1)
        {
                process_error(listx, -1);
                return (1);
        }
        realloc_environ = malloc(sizeof(char *) * (i));
        for (i = j = 0; listx->_environ[i]; i++)
        {
                if (i != k)
                {
                        realloc_environ[j] = listx->_environ[i];
			 j++;
                }
        }
        realloc_environ[j] = NULL;
        free(listx->_environ[k]);
        free(listx->_environ);
        listx->_environ = realloc_environ;
        return (1);
}
