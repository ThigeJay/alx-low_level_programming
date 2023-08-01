#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals
 * @a: square matrix pointer.
 * @size: matrix size
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	unsigned int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + i * size + i);
		sum2 += *(a + (i + 1) * (size - 1));
	}

	printf("%d, %d\n", sum1, sum2);
}
