#include "main.h"

/**
 * print_number - prints an integer in standard output
 * @n: the integer to be printed.
 */
void print_number(int n)
{
	char num_str[12] = {0};
	int i = 0;
	unsigned int abs_n = n < 0 ? -n : n;

	if (n < 0)
		_putchar('-');

	do {
		num_str[i++] = (abs_n % 10) + '0';
		abs_n /= 10;
	} while (abs_n);

	while (i--)
		_putchar(num_str[i]);
}

/**
 * print_diagsums - sum of the two diagonals.
 * @a: pointer.
 * @size: the matrix.
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - i - 1)];
	}

	print_number(sum1);
	_putchar(',');
	_putchar(' ');
	print_number(sum2);
	_putchar('\n');
}

/**
 * _putchar - character in std output.
 * @c: character to be written
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
