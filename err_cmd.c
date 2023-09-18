#include "shell.h"

/**
 * cd_err- function that contain the message for cd error
 *
 * @listx: args lists
 * @msg: message to print
 * @msgOUT: output message
 * @str_tally: counter lines
 * Return: error report
 */
char *cd_err(inventory_t *listx, char *msg, char *msgOUT, char *str_tally)
{
	char *fflag;

	_strcpy(msgOUT, listx->argv[0]);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, str_tally);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, listx->envlist[0]);
	_strcate(msgOUT, msg);

	if (listx->envlist[1][0] == '-')
	{
		fflag = malloc(3);
		fflag[0] = '-';
		fflag[1] = listx->envlist[1][1];
		fflag[2] = '\0';
		_strcate(msgOUT, fflag);
		free(fflag);
	}
	else
	{
		_strcate(msgOUT, listx->envlist[1]);
	}

	_strcate(msgOUT, "\n");
	_strcate(msgOUT, "\0");
	return (msgOUT);
}
/**
 * fetch_cd_err - error report that comes from the command fetch_cd
 * @listx: arguments lists
 * Return: error report
 */
char *fetch_cd_err(inventory_t *listx)
{
	int len, len_id;
	char *msgOUT, *str_tally, *msg;

	str_tally = int_to_str(listx->commd_tally);
	if (listx->envlist[1][0] == '-')
	{
		msg = ": Invalid option ";
		len_id = 2;
	}
	else
	{
		msg = ": Failure to cd to ";
		len_id = _strlen(listx->envlist[1]);
	}

	len = _strlen(listx->argv[0]) + _strlen(listx->envlist[0]);
	len += _strlen(str_tally) + _strlen(msg) + len_id + 5;
	msgOUT = malloc(sizeof(char) * (len + 1));

	if (msgOUT == 0)
	{
		free(str_tally);
		return (NULL);
	}

	msgOUT = cd_err(listx, msg, msgOUT, str_tally);

	free(str_tally);

	return (msgOUT);
}
/**
 * UNfound - enique error report for the command that is not found
 * @listx: arguments lists
 * Return: error report
 */
char *UNfound(inventory_t *listx)
{
	int len;
	char *msgOUT, *str_tally;

	str_tally = int_to_str(listx->commd_tally);
	len = _strlen(listx->argv[0]) + _strlen(str_tally);
	len += _strlen(listx->envlist[0]) + 16;
	msgOUT = malloc(sizeof(char) * (len + 1));
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
	_strcate(msgOUT, ": Invalid\n");
	_strcate(msgOUT, "\0");
	free(str_tally);
	return (msgOUT);
}

/**
 * ex_error - enique error report to exit
 * @listx: arguments lists
 * Return: error report
 */
char *ex_error(inventory_t *listx)
{
	int len;
	char *msgOUT, *str_tally;

	str_tally = int_to_str(listx->commd_tally);
	len = _strlen(listx->argv[0]) + _strlen(str_tally);
	len += _strlen(listx->envlist[0]) + _strlen(listx->envlist[1]) + 23;
	msgOUT = malloc(sizeof(char) * (len + 1));
	if (msgOUT == 0)
	{
		free(str_tally);
		return (NULL);
	}
	_strcpy(msgOUT, listx->argv[0]);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, str_tally);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, listx->envlist[0]);
	_strcate(msgOUT, ": Invalid number: ");
	_strcate(msgOUT, listx->envlist[1]);
	_strcate(msgOUT, "\n\0");
	free(str_tally);

	return (msgOUT);
}
