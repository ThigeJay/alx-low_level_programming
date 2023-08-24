#include "function_pointers.h"

/**
 * int_index - Searches for an integer in the array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @cmp: Pointer to the comparison function.
 *
 * Description: Iterates the array and applies the "cmp" function.
 * Returns the index of the first element for which the cmp function
 * does not return 0. If no element matches or size is <= 0, returns -1.
 *
 * Return: Index of the first match or -1 if no match.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (!array || size <= 0 || !cmp)
		return (-1);

	for (index = 0; index < size; index++)
	{
		if (cmp(array[index]))
			return (index);
	}

	return (-1);
}
