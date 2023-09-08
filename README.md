SIMPLE SHELL PROJECT

This is a custom shell command line intepreter which takes the command inputs written from the user's keyboard and passes them to the machine to execute them through the kernel just like a regular shell. It also validates correct command inputs.

Here are the files that enables JH_shell emulates shell:

#display_prompt.c

The display_prompt function displays a prompt " $"
by writing it to stdout using the write function

the read_commd reads user's command input, using the getline function it reads input line
and checks if the command is exit to end the program.

the exe_cmmd function executes the given command by forking a child process. The child process executes
command using the execve function while the parent process waits for the completion of child process using the wait function before executing

the main function starts an infinite loop where it call all the above mentioned functions, and at the end frees the memory of the command string.

#Custom getline _getline()

The getline function takes the address of a pointer to an input commands buffer and the maxsize of the input character string as input. it calls read() with the file descriptor set to STDIN and reads from STDIN one character at a time.The process stops when "\n" is encountered. Each character is stored in buffer, and the buffer is reallocated as necessary to accomodate a large string. It then returns the total size of the string read as history.


Authors:
ONOGE HENRIETTA
FAITH SUBERU
