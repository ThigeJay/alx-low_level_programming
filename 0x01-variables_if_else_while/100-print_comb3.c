#include <stdio.h>

/**
 * main - start of program
 * Description: Program prints all possible different
 * combinations of
 * two digits,separeted by , and followed by a space.
 *
 * Return: (0) on success
*/
int main(void)
{
	int number, p;

	for (number = 48; number <= 56; number++)
	{
		for (p = 49; p <= 57; p++)
		{
			if (p > number)
			{
				putchar(number);
				putchar(p);
				if (number != 56 || p != 57)
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
