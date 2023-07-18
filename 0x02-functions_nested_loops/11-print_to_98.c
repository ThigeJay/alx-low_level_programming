#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - print natural numbers from n to 98
 * followed by a new line
 * @n: start of printing
 */
void print_to_98(int n)
{
	int nmber1, number2;

	if (n <= 98)
	{
		for (number1 = n; number1 <= 98; number1++)
		{
			if (number1 != 98)
				printf("%d, ", number1);
			else if (number1 == 98)
				printf("%d\n", number1);
		}
	} else if (n >= 98)
	{
		for (number2 = n; number2 >= 98; number2--)
		{
			if (j != 98)
				printf("%d, ", number2);
			else if (number2 == 98)
				printf("%d\n", number2);
		}
	}
}
