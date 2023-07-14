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
	int n;

	for (n = 48; n < 58; n++)
	{
		putchar(n);
		if (n != 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
