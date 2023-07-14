#include <stdio.h>

/**
 * main - start of program
 * Description: Program prints all possible combinations of
 * single-digit numbers separated by comas and tabs
 * and a new line at the end
 *
 * Return: (0) on success
*/
int main(void)
{
	int digit1;
	int digit2;

	for (digit1 = 0; digit1 < 9; digit1++)
	{
		for (digit2 = digit1 + 1; digit2 <= 9; digit2++)
		{
			putchar(digit1 + '0');
			putchar(',');
			putchar('\t');
			putchar(digit2 + '0');

			if (!(digit1 == 8 && digit2 == 9))
			{
				putchar(',');
				putchar('\t');
			}
		}
	}

	putchar('\n');

	return (0);
}
