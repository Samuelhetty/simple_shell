#include "shell.h"


/**
 * err_env - error report for the env in fetch_env.
 * @listx: argument lists
 * Return: error report
 */
char *err_env(inventory_t *listx)
{
	int len;
	char *msgOUT, *msg, *str_tally;

	str_tally = int_to_str(listx->commd_tally);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(listx->argv[0]) + _strlen(str_tally);
	len += _strlen(listx->envlist[0]) + _strlen(msg) + 4;
	msgOUT = safe_malloc(sizeof(char) * (len + 1));
	if (msgOUT == 0)
	{
		free(msgOUT);
		free(str_tally);
		return (NULL);
	}

	_strcpy(msgOUT, listx->argv[0]);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, str_tally);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, listx->envlist[0]);
	_strcate(msgOUT, msg);
	_strcate(msgOUT, "\0");
	free(str_tally);

	return (msgOUT);
}

/**
 * path_err - error report for the path.
 * @listx: argument lists
 * Return: error report
 */
char *path_err(inventory_t *listx)
{
	int len;
	char *msgOUT, *str_tally;

	str_tally = int_to_str(listx->commd_tally);
	len = _strlen(listx->argv[0]) + _strlen(str_tally);
	len += _strlen(listx->envlist[0]) + 24;
	msgOUT = safe_malloc(sizeof(char) * (len + 1));
	if (msgOUT == 0)
	{
		free(msgOUT);
		free(str_tally);
		return (NULL);
	}
	_strcpy(msgOUT, listx->argv[0]);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, str_tally);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, listx->envlist[0]);
	_strcate(msgOUT, ": Entry denied\n");
	_strcate(msgOUT, "\0");
	free(str_tally);
	return (msgOUT);
}
/**
 * ezit_shell - exits the shell
 *
 * @listx: argument lists
 * Return: error report
 */
/*int ezit_shell(inventory_t *listx)
{
	unsigned int es;
	int digit, lenstr, bg_num;

	if (listx->envlist[1] != NULL)
	{
		es = _atoi(listx->envlist[1]);
		digit = _isdigit(listx->envlist[1]);
		lenstr = _strlen(listx->envlist[1]);
		bg_num = es > (unsigned int)INT_MAX;
		if (!is_digit || lenstr > 10 || bg_num)
		{
			process_error(listx, 2);
			listx->exit_status = 2;
			return (1);
		}
		listx->exit_status = (es % 256);
	}*/
