#include "main.h"
/**
 * puts_half - function that prints half of a string, followed by a new line
 * The function should print the second half of the string
 * @str: input
 * Return: half of user input
 */
void puts_half(char *str)
{
	int x, n, length;

	length = 0;

	for (x = 0; str[x] != '\0'; x++)
		length++;

	n = (length / 2);

	if ((length % 2) == 1)
		n = ((length + 1) / 2);

	for (x = n; str[x] != '\0'; x++)
		_putchar(str[x]);
	_putchar('\n');
}
