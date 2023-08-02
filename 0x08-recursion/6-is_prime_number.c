#include "main.h"

/**
 * is_divisible - checks if number is divisible
 * @n: number1
 * @i: number2
 * Return: 0 if not divible by self. 1 if divisible
 */
int is_divisible(int n, int i)
{
	if (n % i == 0)
	{
		return (0);
	}
	if (i == n / 2)
	{
		return (1);
	}
	return (is_divisible(n, i + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: integer
 *
 * Return: 0 if number not prime,1 if it is
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (is_divisible(n, 2));
}
