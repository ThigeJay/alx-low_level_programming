#include <stdio.h>

/**
 * main - start of program
 * Description: The program prints the alphabet in lowercase,
 * followed by a new line. It doesnt print letter 'q' and 'e'
 *
 * Return: (0) on success
*/
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (letter != 'q' && letter != 'e')
		{
			putchar(letter);
		}
	}

	putchar('\n');

	return (0);
}
