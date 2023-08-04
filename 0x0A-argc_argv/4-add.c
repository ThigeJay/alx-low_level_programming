#include "main.h"

/**
 * main - Entry; multiplies two numbers passed as arguments.
 * atoi - converts a string to an integer
 * @argc: Number of arguments passed.
 * @argv: Array of arguments.
 *
 * Return:0 on success, 1 if one of the numbers not a digit
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int x, y;

	for (x = 1; x < argc; x++)
	{
		for (y = 0; argv[x][y] != '\0'; y++)
		{
			if (argv[x][y] < '0' || argv[x][y] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[x]);
	}

	printf("%d\n", sum);

	return (0);
}
