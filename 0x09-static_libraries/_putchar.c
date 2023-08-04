#include <stdio.h>
#include "main.h"

/**
 * main - entry point of program
 * Description: prints _putchar
 * Return: 0 always on success.
*/

int main(void)
{
	char str[] = "_putchar\n";
	int x = 0;

	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
	return (0);
}
