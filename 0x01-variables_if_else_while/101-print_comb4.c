#include <stdio.h>

/**
 * main - start of program
 * Description: Program prints different
 * combinations of
 * three digits,separeted by , and followed by a space.
 *
 * Return: (0) on success
*/
int main(void)
{
	int number, digit, list;

	for (number = 48; number < 58; number++)
	{
		for (digit = 49; digit < 58; digit++)
		{
			for (list = 50; list < 58; list++)
			{
				if (list > digit && digit > number)
				{
					putchar(number);
					putchar(digit);
					putchar(list);
					if (number != 55 || digit != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
