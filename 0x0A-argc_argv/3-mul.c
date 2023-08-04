#include "main.h"

/**
 * main - Entry; multiplies two numbers passed as arguments.
 * atoi - converts a string to an integer
 * @argc: Number of arguments passed.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 if not PRECISELY 2 arguments are passed.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);

		printf("%d\n", num1 * num2);
	}

	return (0);
}
