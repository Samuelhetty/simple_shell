#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to reallocate memory
 * @old_size: size in bytes of allocated memory
 * @new_size: newsize of memory block in bytes
 *
 * Return: void pointer to new allocation of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *NEWp;
	unsigned int i;

	if (!ptr)
	{
		NEWp = safe_malloc(new_size);
		return (NEWp);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == new_size)
		return (ptr);

	NEWp = safe_malloc(new_size);

	if (!NEWp)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
	{
		NEWp[i] = ((char *)ptr)[i];
	}

	free(ptr);

	return (NEWp);
}
/**
 * dptr_alloc - reallocates a memory block of a two pointer
 * @dptr: two pointer to the previous memory allocated
 * @old: size in bytes of the allocated space of dptr
 * @new: new size in bytes of the new memory block
 *
 * Return: dptr.
 * if new == size, returns dptr without any changes.
 * if malloc fails, returns NULL.
 */
char **dptr_alloc(char **dptr, unsigned int old, unsigned int new)
{
	char **n_ptr;
	unsigned int i;

	if (dptr == NULL)
		return (safe_malloc(sizeof(char *) * new));

	if (new == old)
		return (dptr);

	n_ptr = safe_malloc(sizeof(char *) * new);
	if (n_ptr == NULL)
		return (NULL);

	for (i = 0; i < old; i++)
		n_ptr[i] = dptr[i];

	free(dptr);

	return (n_ptr);
}

/**
 * mem_reset - sets all bytes of string to '\0'
 * @str: string
 * @bytes: number of bytes
 *
 * Return: pointer to string with reset mem
 */
char *mem_reset(char *str, int bytes)
{
	int i = 0;

	while (i < bytes)
	{
		str[i++] = '\0';
	}
	return (str);
}

/**
 * safe_malloc - mallocs memory of size bytes, prints error message on error
 * @bytes: number of bytes to malloc
 *
 * Return: pointer to malloced memory or NULL
 */
void *safe_malloc(int bytes)
{
	void *check;

	check = malloc(bytes);

	if (check == NULL)
	{
		_perror("No Memory\n");
		exit(1);
	}
	check = mem_reset(check, bytes);

	return (check);
}

/**
 * _perror - custom perror
 * @string: input error string to write to stderr
 *
 * Return: void
 */
void _perror(const char *string)
{
	size_t len;

	len = _strlen(string);

	write(STDERR_FILENO, string, len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, strerror(errno), _strlen(strerror(errno)));
	write(STDERR_FILENO, "\n", 1);
}
