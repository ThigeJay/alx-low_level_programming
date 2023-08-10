#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - Allocates a specified number of bytes of memory.
 * @b: Number of bytes to allocate.
 *
 * If memory allocation fails, the function exits the program
 * with an exit status of 98.
 *
 * Return: A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *allocated_mem;

	allocated_mem = malloc(b);

	if (allocated_mem == NULL)
		exit(98);

	return (allocated_mem);
}
