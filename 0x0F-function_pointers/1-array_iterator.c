#include "function_pointers.h"

/**
 * array_iterator - Iterates over the elements of an array
 * @array: The array to iterate over.
 * @size: The number of elements in the array.
 * @action: A pointer to a function
 * Description: If 'array' is NULL, 'size' is non-positive.
 * Return: The index of the first true element, or -1 if none.
 */
int array_iterator(int *array, size_t size, int (*action)(int))
{
	size_t index;

	if (array == NULL || size <= 0 || action == NULL)
		return (-1);

	for (index = 0; index < size; index++)
	{
		if (action(array[index]))
			return (index);
	}

	return (-1);
}
