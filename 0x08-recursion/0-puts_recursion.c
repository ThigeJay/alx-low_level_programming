#include "main.h"
/**
 * _puts_recursion - the function we working with
 * @s: user input
 * Return: 0 on success
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}

	else
		_putchar('\n');
}
