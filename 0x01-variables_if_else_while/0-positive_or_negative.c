#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Description: The program assigns a random number to the variable 'n'
 *              and prints whether the number is positive, negative, or zero.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() % 99 - 1;

	printf("The number is %d", n);

	if (n > 0)
	{
		printf(" positive\n");
	}
	else if (n == 0)
	{
		printf(" zero\n");
	}
	else
	{
		printf(" negative\n");
	}

	return (0);
}
