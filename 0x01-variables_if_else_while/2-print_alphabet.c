#include <stdio.h>

/**
 * main - start of program
 * Description: Prints the alphabet in lowercase, followed by a new line
 *
 * Return: (0) on success
*/
int main(void)
{
	char start = 'a';
	char end = 'z';

	while (start <= end)
	{
		putchar(start);
		start++;
	}

	putchar('\n');

	return (0);
}
