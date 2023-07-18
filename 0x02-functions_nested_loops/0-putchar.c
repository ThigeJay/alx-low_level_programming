#include <stdio.h>
#include <main.h>

/**
 * main - entry point of program
 * Description: this program prints _putchar followed by new line.
 * Return: 0 always on success.
*/

int main(void)
{
	char str[] = "_putchar\n";
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (0);
}
