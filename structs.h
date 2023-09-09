#ifndef STRUCT
#define STRUCT


/**
 * struct cmmd_s - struct for storing command line
 * @cmmd: cmmand line
 * @next: next node
 *
 */
typedef struct cmmd_s
{
	char *cmmd;
	struct cmmd_s *next;
} cmmd_t;


/**
 * struct token_s - struct for tokenizing string
 * @tokens: ; | &
 * @next: next node
 *
 */
typedef struct token_s
{
    char tokens;
    struct token_s *next;
} tokens_t;

/**
 * struct list_s - struct for holding custom environmental variables list
 * @var: environmental variable and value separated by '=' char
 * @val: value of env var
 * @next: pointer to the next env variable node
 */
typedef struct list_s
{
    char *var;
    char *val;
    struct list_s *next;
} list_t;

/**
 * struct inventory - inventory of support arguments for immediate access
 * @N_commd: str of input commands
 * @envlist: custom environ linked list
 * @buflimit: buflimit max of 1024 chars
 * @st_mode: set mode to either FIFO or terminal
 * @commd: double pointer to commands list
 * @tokens: tokens list
 * @last_bg_pid: last pid
 * @num_bg_jobs: background count
 * @exit: the exit indicator
 * @exit_status: the exit status
 */
typedef struct inventory
{
    char *N_commd;
    char **commd;
    int st_mode;
    list_t *envlist;
    size_t buflimit;
    tokens_t tokens;
    int num_bg_jobs;

    pid_t last_bg_pid;

    int exit;
    int exit_status;

} inventory_t;

/**
 * struct _builtins - matches command to appropriate builtin function
 * @commd: string command for builtin
 * @builtin_func: function to handle builtin command
 */
typedef struct _builtins
{
    char *commd;
    int (*builtin_func)(inventory_t *listx);
} builtins_t;


#endif
