#include <stdio.h>

/**
 * main - start of program
 * Description: The program prints the alphabet in lowercase,
 * Then in uppercase, followed by a new line
 *
 * Return: (0) on success
*/
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}

	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		putchar(letter);
	}

	putchar('\n');

	return (0);
}
