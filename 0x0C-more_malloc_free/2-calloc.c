#include <stdlib.h>
#include "main.h"

/**
 * _memset - Fills the first 'n' bytes of the memory area pointed to by 's'
 * with the constant byte 'b'.
 * @s: Pointer to the memory area to be filled.
 * @b: The constant byte to set.
 * @n: Number of bytes to be set to the value 'b'.
 *
 * Return: A pointer to the filled memory area 's'.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int idx;

	for (idx = 0; idx < n; idx++)
	{
		s[idx] = b;
	}

	return (s);
}

/**
 * _calloc - Allocates memory for an array, and initializes all bytes to zero.
 * @nmemb: Number of elements in the array.
 * @size: Size in bytes of each element.
 *
 * If nmemb or size is 0, the function returns NULL.
 *
 * Return: A pointer to the allocated memory, initialized to zero.
 * Returns NULL if memory allocation fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *allocated_mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	allocated_mem = malloc(size * nmemb);

	if (allocated_mem == NULL)
		return (NULL);

	_memset(allocated_mem, 0, nmemb * size);

	return (allocated_mem);
}
