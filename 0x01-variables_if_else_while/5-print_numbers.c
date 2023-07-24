#include <stdio.h>

/**
 * main - start point of the program
 * Description: program prints all single digit
 * numbers of base 10 starting from 0,
 * followed by a new line.
 *
 * Return: 0 on success.
*/
int main(void)
{
	int digit;

	for (digit = 0; digit < 10; digit++)
	{
		printf("%d", digit);
	}
	putchar('\n');
	return (0);
}
