#include "main.h"
/**
 * _puts - progrm prints a given  string,followed by a new line.
 * @str: string that will be printed
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
		_putchar('\n');
}
