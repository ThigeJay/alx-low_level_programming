#include "main.h"

/**
 *print_binary - Prints the binary representation of a number.
 *@n: The number.
 */
void print_binary(unsigned long int n)
{
	unsigned long int new = 1;
	int started = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	new <<= ((sizeof(unsigned long int) * 8) - 1);

	while (new)
	{
		if (n & new)
		{
			_putchar('1');
			started = 1;
		}
		else if (started)
		{
			_putchar('0');
		}
		new >>= 1;
	}
}
