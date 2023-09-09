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

/* -----environ----- */
extern char **environ;


/* -----argument inventory----- */
inventory_t *buildarginv(void);


/* -----custom environ----- */
list_t *env_list(void);
unsigned int link_tally(list_t *head);
char **L_list_to_dptr(list_t *head);
int pt_env(inventory_t *listx);
size_t print_list(list_t *head);
list_t *add_node_end(list_t **head, char *var, char *val);
char **split_str(char *str);
int free_env(list_t *head);

/*------------main-----------*/
void display_prompt(int signa);
int _filemode(int fd);

/* ---------------custom malloc--------------- */
char *mem_reset(char *str, int bytes);
void *safe_malloc(int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* -----custom C std lib----- */
void _perror(const char *string);
ssize_t _getline(char **buffer, size_t *LTD);
ssize_t _readline(int fd, char **buffer, size_t *LTD);


/*---------strings-----------*/
size_t __attribute__ ((warn_unused_result)) _strlen(const char *s);
char *_strncate(char *dest, char *src, int n);
int _putzar(char c);
int _putz(const char *str);
int _stricomp(char *s1, char *s2);
char *_strdupp(char *str);
char *_strcate(char *dest, char *src);
char *hf_strtok(char *str, const char *delim);

#endif
