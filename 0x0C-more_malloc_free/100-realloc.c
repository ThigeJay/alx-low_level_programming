#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the previously allocated memory.
 * @old_size: Size in bytes of the previously allocated memory.
 * @new_size: Size in bytes of the new memory block.
 *
 *  behaves like standard library's realloc function.
 * If new_size equals old_size,function returns 'ptr'(original pointer)
 * If new_size is 0 and ptr is not NULL,free it and retur NULL
 * If ptr is NULL, the function behaves like malloc.
 *
 * Return: Pointer to the newly allocated memory block.
 * return NULL on failure. Returns ptr if new_size equals old_size.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_mem;
	char *src_mem;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	new_mem = malloc(new_size);
	if (!new_mem)
		return (NULL);

	src_mem = ptr;

	unsigned int bytes_to_copy = (new_size < old_size) ? new_size : old_size;
	for (i = 0; i < bytes_to_copy; i++)

		new_mem[i] = src_mem[i];

	free(ptr);
	return (new_mem);
}
