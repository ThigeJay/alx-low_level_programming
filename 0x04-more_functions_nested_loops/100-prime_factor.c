#include <stdio.h>
#include <math.h>

/**
 * main - entry point of the program
 * Description: finds & prints the largest prime factor in the number
 * 612852475143 followed by a new line
 * Return: 0 on success.
 */
int main(void)
{
	long int n;
	long int large;
	long int x;

	n = 612852475143;
	large = -1;

	while (n % 2 == 0)
	{
		large = 2;
		n /= 2;
	}

	for (x = 3; x <= sqrt(n); x = x + 2)
	{
		while (n % x == 0)
		{
			large = x;
			n = n / x;
		}
	}

	if (n > 2)
		large = n;

	printf("%ld\n", large);

	return (0);
}
