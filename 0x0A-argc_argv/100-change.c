#include "main.h"

/**
 * main - Entry; Calculates minimum numberber of coins to make change.
 * atoi - parse the parameter passed to the program
 * @argc: number of arguments passed.
 * @argv: Array of arguments,first one is the program name.
 *
 * Return: 0 on success, 1 if number of arguments is not PRECISELY 1.
 */
int main(int argc, char *argv[])
{
	int number, y, result;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	number = atoi(argv[1]);
	result = 0;

	if (number < 0)
	{
		printf("0\n");
		return (0);
	}

	for (y = 0; y < 5 && number >= 0; y++)
	{
		while (number >= coins[y])
		{
			result++;
			number -= coins[y];
		}
	}

	printf("%d\n", result);
	return (0);
}
