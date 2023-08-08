#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars, and initializes it with
 * a specific char
 * @size: size of the array
 * @c: char to initialize the array with
 *
 * This function allocates memory to hold an array of chars of a given size,
 * then initializes every element in the array with the specified char.
 *
 * Return: pointer to the array, or NULL if size is 0 or
 * the memory allocation fails.
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;

	return (str);
}
