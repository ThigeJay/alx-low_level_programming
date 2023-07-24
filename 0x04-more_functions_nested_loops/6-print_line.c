#include "main.h"

/**
 * print_line - draws a straight line on the terminal
 * @n: the times the character '_' needs to be printed
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int x;

		for (x = 1; x <= n; x++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}

}
