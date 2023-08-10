#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 *
 * acts just like standard library's realloc.
 *
 * @ptr: Pointer to the previously allocated memory (can be NULL).
 * @old_size: Size (in bytes) of the previously allocated memory.
 * @new_size: Desired size (in bytes) for the new memory block.
 *
 * Return: Pointer to he newly allocated memory blockd
 * memory block preserved. Returns NULL if the new memory allocation fails.
 * If new_size is the same as old_size, the original pointer is returned.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
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

	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr1[i] = old_ptr[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr1[i] = old_ptr[i];
	}

	free(ptr);
	return (ptr1);
}
