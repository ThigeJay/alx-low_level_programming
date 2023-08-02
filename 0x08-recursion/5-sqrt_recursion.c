#include "main.h"
/**
 * sqrt_check - pogram checks for the square root of a number
 * @i: number1
 * @n: number2
 *
 * Return: natural square root or -1
 */
int sqrt_check(int i, int n)
{
	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
	{
		return (-1);
	}
	return (sqrt_check(i + 1, n));
}

/**
 * _sqrt_recursion - natural square root of a number
 * @n: integer
 *
 * Return: natural square root. -1 on failure
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
	{
		return (0);
	}
	if (n == 1)
	{
		return (1);
	}
	if (n < 1)
	{
		return (-1);
	}
	return (sqrt_check(1, n));
}
