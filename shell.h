#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stddef.h>
#include "structs.h"

/* -----MACROS----- */
#define BUFSIZE 1024
#define EXT_SUCCESS 0
#define EXT_FAILURE 1
#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define TOK_BUFSIZE 128
#define TOK_DELIMIT " \t\r\n\a"

/* -----environ----- */
extern char **environ;


/* -----argument inventory----- */
void buildarginv(inventory_t *listx, char **av);
void free_cmmd(inventory_t *listx);

/* -----custom environ----- */
int check_ID(const char *n_var, const char *ID);
int pt_env(inventory_t *listx);
char print_list(const char *ID, char **_environ);
char *bash_replace(char *N_commd, inventory_t *listx);
char *replaced_var(list_t **head, char *N_commd, char *N_input, int N_len);
int identify_vars(list_t **head, char *input, char *last_bg_status, inventory_t *envlist);
void perform_search(list_t **head, char *input, inventory_t *envlist);
list_t *add_node_end(list_t **head, char *value, int var, int val);
void free_list(list_t **head);
char *read_commd(int *i_eof);

/*------------main-----------*/
void display_prompt(int signa);
int _filemode(int fd);
void run_shell(inventory_t *listx);

/* ---------------custom malloc--------------- */
char *mem_reset(char *str, int bytes);
void *safe_malloc(int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* -----custom C std lib----- */
void _perror(const char *string);
ssize_t _getline(char **buffer, size_t *LTD);
ssize_t _readline(int fd, char **buffer, size_t *LTD);
void hf_print(const char *prints);

/*------------builtins-----------*/
void ezit(void);

/*---------strings-----------*/
size_t __attribute__ ((warn_unused_result)) _strlen(const char *s);
char *_strncate(char *dest, char *src, int n);
int _putzar(char c);
int _putz(const char *str);
int _stricomp(char *s1, char *s2);
char *_strdupp(char *str);
char *_strcate(char *dest, char *src);
char *hf_strtok(char *str, const char *delim);
int str_to_int(const char *c);
void int_to_str(int num, char* string);


/*-----------tokens----------*/
char *ex_char(char *N_commd, int boll);
void add_nodes(tokens_t **h1, cmmd_t **h2, char *N_commd);
void fetch_commd(tokens_t **tok_list, cmmd_t **cmmd_list, inventory_t *listx);
int tokenize_cmmd(inventory_t *listx, char *N_commd);
char **tokenize(char *N_commd);
void add_tok_node_end(tokens_t **head, char tokens);
void add_cmmd_node_end(cmmd_t **head, char *cmmd);
void free_commd(cmmd_t **head);
void free_tok(tokens_t **head);

#endif
