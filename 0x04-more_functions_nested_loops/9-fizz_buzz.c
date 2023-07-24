#include "main.h"
#include <stdio.h>

/**
 * main - entry point of the program
 * Description: program prints numbers from 1 to 100,
 * followed by a new line.
 * For multiples of 3 it prints Fizz.
 * For multiples of 5 it prints Buzz
 * In neither, it prints the number itself.
 * Return: 0 on sucess.
 */
int main(void)
{
	int x;

	for (x = 1; x <= 100; x++)
	{
		if (x % 3 == 0 && x % 5 != 0)
		{
			printf(" Fizz");
		} else if (x % 5 == 0 && x % 3 != 0)
		{
			printf(" Buzz");
		} else if (x % 3 == 0 && x % 5 == 0)
		{
			printf(" FizzBuzz");
		} else if (x == 1)
		{
			printf("%d", x);
		} else
		{
			printf(" %d", x);
		}
	}
	printf("\n");

	return (0);
}
