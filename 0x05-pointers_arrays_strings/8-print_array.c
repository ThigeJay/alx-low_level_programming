#include "main.h"

/**
 * print_array - prints n elements of an array
 * @a: name of the array
 * @n: number of elements of array to be printed
 * Return: the inputs of a and n
 */
void print_array(int *a, int n)
{
	int x;

	for (x = 0; x < (n - 1); x++)
	{
		printf("%d, ", a[x]);
	}
		if (x == (n - 1))
		{
			printf("%d", a[n - 1]);
		}
			printf("\n");
}
