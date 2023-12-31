#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @action: Pointer to the function to be executed on each array element.
 *
 * Description: goes through the array and applies the "action"
 * If "array" or "action" is NULL, the function returns.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
