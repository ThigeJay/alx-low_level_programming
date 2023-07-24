#include <stdio.h>

/**
 * main - start of program
 * Description: prints all numbers of base 16 in lowercase,
 * followed by a new line.
 *
 * Return: (0) on success
*/
int main(void)
{
	int digit;

	for (digit = 0; digit < 10; digit++)
	{
		putchar(digit + '0');
	}

	for (digit = 0; digit < 6; digit++)
	{
		putchar(digit + 'a');
	}

	putchar('\n');

	return (0);
}
