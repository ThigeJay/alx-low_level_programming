#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: The number of parameters.
 * Description: Contains the implementation of the function sum_them_all.
 *
 * Return: The sum of all its parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int counter;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(args, n);

	for (counter = 0; counter < n; counter++)
	{
		sum += va_arg(args, int);
	}

	va_end(args);

	return (sum);
}
