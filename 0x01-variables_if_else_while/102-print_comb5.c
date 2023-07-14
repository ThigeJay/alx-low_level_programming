#include <stdio.h>

/**
 * main - start of program
 * Description: Program  prints all possible combinations
 * of two two-digit numbers.
 * range 0-99 and followed by a space.
 *
 * Return: (0) on success
*/
int main(void)
{
	int number1, number2;

	for (number1 = 0; number1 < 100; number1++)
	{
		for (number2 = 0; number2 < 100; number2++)
		{
			if (number1 < number2)
			{
				putchar((number1 / 10) + 48);
				putchar((number1 % 10) + 48);
				putchar(' ');
				putchar((number2 / 10) + 48);
				putchar((number2 % 10) + 48);
				if (number1 != 98 || number2 != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}

		}
	}
	putchar('\n');
	return (0);
}
