#include <stddef.h>

/**
 * _memset - fills memory with a specific value.
 * @s: A pointer to the memory area to be changed
 * @b: constant value
 * @n: The number of bytes to be changed
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		s[x] = b;
	}

	return (s);
}
