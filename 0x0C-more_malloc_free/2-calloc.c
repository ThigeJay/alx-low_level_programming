#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers from min to max inclusive.
 * @min: The starting value of the range of integers.
 * @max: The ending value of the range of integers.
 *
 * If min is > max, return NULL.
 *
 * Return: A pointer to the newly allocated array.
 * return NULL if memory allocation fails or
 * min is greater than max
 */
int *array_range(int min, int max)
{
	int *int_array;
	int i, array_size;

	if (min > max)
		return (NULL);

	array_size = max - min + 1;

	int_array = malloc(sizeof(int) * array_size);

	if (int_array == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		int_array[i] = min++;

	return (int_array);
}
