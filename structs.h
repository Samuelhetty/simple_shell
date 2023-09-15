#ifndef STRUCT
#define STRUCT


/**
 * struct inventory - inventory of support arguments for immediate access
 * @argv: argument vector
 * @N_commd: str of input commands
 * @st_mode: set mode to either FIFO or terminal
 * @envlist: double pointer to commands list
 * @commd_tally: counter
 * @pid: processs id of the shell
 * @exit: the exit indicator
 * @exit_status: the exit status
 */
typedef struct inventory
{
        char **argv;
        char *N_commd;
        char **envlist;
        int st_mode;
        int commd_tally;
        char **_environ;
        char *pid;
        int exit;
        int exit_status;

} inventory_t;

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
 * struct list_s - struct for holding custom environmental variables list
 * @var: environmental variable and value separated by '=' char
 * @val: value of env var
 * @next: pointer to the next env variable node
 */
typedef struct list_s
{
    int var;
    int val;
    char *value;
    struct list_s *next;
} list_t;

/**
 * struct _builtins - matches command to appropriate builtin function
 * @args: string command for builtin
 * @builtin_func: function to handle builtin command
 */
typedef struct _builtins
{
    char *args;
    int (*builtin_func)(inventory_t *listx);
} builtins_t;


#endif
