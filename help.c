#include "shell.h"

/**
 * h_env - help the codes for builtin of env
 * Return: zero return
 */
void h_env(void)
{
	char *help = "env: env [option] [name=value] [command [envlist]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Display all environmental variables,in the form:.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}

/**
 * help_all - start point to help the codes for builtin general
 * Return: zero return
 */
void help_all(void)
{
	char *help = "$ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[directories]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * h_exit - help the codes for builtin exit
 * Return: zero return
 */
void h_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "status is that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * hf_help - help the codes for builtin help.
 * Return: zero return
 */
void hf_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
