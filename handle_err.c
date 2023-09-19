#include "shell.h"

/**
 * ch_dupp - sum of the repetitions of a char
 * @N_commd: input str
 * @i: index
 * Return: repetitions
 */
int ch_dupp(char *N_commd, int i)
{
	if (*(N_commd - 1) == *N_commd)
		return (ch_dupp(N_commd - 1, i + 1));

	return (i);
}
/**
 * fetch_err - allocate syntax errors
 *
 * @N_commd: input str
 * @i: index
 * @end: last char read
 * Return: index of error, and 0 when there are no errors
 */
int fetch_err(char *N_commd, int i, char end)
{
	int tally = 0;

	if (*N_commd == '\0')
		return (0);

	if (*N_commd == ' ' || *N_commd == '\t')
		return (fetch_err(N_commd + 1, i + 1, end));

	if (*N_commd == ';')
		if (end == '|' || end == '&' || end == ';')
			return (i);

	if (*N_commd == '|')
	{
		if (end == ';' || end == '&')
			return (i);

		if (end == '|')
		{
			tally = ch_dupp(N_commd, 0);
			if (tally == 0 || tally > 1)
				return (i);
		}
	}

	if (*N_commd == '&')
	{
		if (end == ';' || end == '|')
			return (i);

		if (end == '&')
		{
			end = ch_dupp(N_commd, 0);
			if (tally == 0 || tally > 1)
				return (i);
		}
	}

	return (fetch_err(N_commd + 1, i + 1, *N_commd));
}
/**
 * char_entry - sum of the first of a char
 * @N_commd: input str
 * @indx: index
 * Return: 1 if there if an error and 0 in other occasion
 */
int char_entry(char *N_commd, int *indx)
{
	for (*indx = 0; N_commd[*indx]; *indx += 1)
	{
		if (N_commd[*indx] == ' ' || N_commd[*indx] == '\t')
			continue;

		if (N_commd[*indx] == ';' || N_commd[*indx] == '|' || N_commd[*indx] == '&')
			return (-1);

		break;
	}

	return (0);
}


/**
 * pt_error - print out when a syntax error is found
 * @listx: file structure
 * @N_commd: input str
 * @indx: index of the error
 * @bool: to control the massage error
 * Return: zero return
 */
void pt_error(inventory_t *listx, char *N_commd, int indx, int bool)
{
	char *msg, *msg2, *msg3, *msgOUT, *commd_tally;
	int length;

	if (N_commd[indx] == ';')
	{
		if (bool == 0)
			msg = (N_commd[indx + 1] == ';' ? ";;" : ";");
		else
			msg = (N_commd[indx - 1] == ';' ? ";;" : ";");
	}

	if (N_commd[indx] == '|')
		msg = (N_commd[indx + 1] == '|' ? "||" : "|");

	if (N_commd[indx] == '&')
		msg = (N_commd[indx + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	commd_tally = int_to_str(listx->commd_tally);
	length = _strlen(listx->argv[0]) + _strlen(commd_tally);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	msgOUT = safe_malloc(sizeof(char) * (length + 1));
	if (msgOUT == 0)
	{
		free(commd_tally);
		return;
	}
	_strcpy(msgOUT, listx->argv[0]);
	_strcate(msgOUT, ": ");
	_strcate(msgOUT, commd_tally);
	_strcate(msgOUT, msg2);
	_strcate(msgOUT, msg);
	_strcate(msgOUT, msg3);
	_strcate(msgOUT, "\0");

	write(STDERR_FILENO, msgOUT, length);
	free(msgOUT);
	free(commd_tally);
}

/**
 * process_error - calls the error according the builtin, syntax or permission
 * @listx: argument list
 * @e_val: error value
 * Return: error
 */
int process_error(inventory_t *listx, int e_val)
{
	char *msgOUT;

	switch (e_val)
	{
	case -1:
		msgOUT = err_env(listx);
		break;
	case 126:
		msgOUT = path_err(listx);
		break;
	case 127:
		msgOUT = UNfound(listx);
		break;
	case 2:
		if (hf_strcmp("exit", listx->envlist[0]) == 0)
			msgOUT = ex_error(listx);
		else if (hf_strcmp("cd", listx->envlist[0]) == 0)
			msgOUT = fetch_cd_err(listx);
		break;
	}

	if (msgOUT)
	{
		write(STDERR_FILENO, msgOUT, _strlen(msgOUT));
		free(msgOUT);
	}

	listx->exit_status = e_val;
	return (e_val);
}
