#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - Executes simple mathematical operations.
 * @argc: The count of command-line arguments.
 * @argv: The command-line arguments.
 *
 * Description:
 * Uses a function pointer to match and execute the correct operation.
 *
 * Return: 0 on success, various error codes on failure.
 */
int main(int argc, char *argv[])
{
	int number1, number2;
	char *operator;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	number1 = atoi(argv[1]);
	operator = argv[2];
	number2 = atoi(argv[3]);

	if (get_op_func(operator) == NULL || operator[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((operator[0] == '/' && number2 == 0) ||
	    (operator[0] == '%' && number2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(operator)(number1, number2));

	return (0);
}
