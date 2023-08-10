#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - Check if a string consists numeric characters.
 * @str: The string to evaluate.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int is_digit(char *str)
{
	int index = 0;

	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

/**
 * string_length - Compute the length of a string.
 * @str: The string whose length is to be determined.
 *
 * Return: The number of characters in the string
 * excluding the terminating NULL character
 */
int string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * print_error_and_exit - Prints an error message and exits the program.
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply_numbers - Multiplies two positive numbers
 * @num1: First number as a string.
 * @num2: Second number as a string.
 * @product: Resultant product array.
 */
void multiply_numbers(char *num1, char *num2, int *product)
{
	int len_str1, len_str2, carry, num1_digit, num2_digit, i;

	len_str1 = string_length(num1);
	len_str2 = string_length(num2);

	for (len_str1--; len_str1 >= 0; len_str1--)
	{
		num1_digit = num1[len_str1] - '0';
		carry = 0;

		for (len_str2 = string_length(num2) - 1; len_str2 >= 0; len_str2--)
		{
			num2_digit = num2[len_str2] - '0';
			carry += product[len_str1 + len_str2 + 1] + (num1_digit * num2_digit);
			product[len_str1 + len_str2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			product[len_str1 + len_str2 + 1] += carry;
	}
}

/**
 * main - Entry point. Multiplies two positive numbers passed as strings.
 * @argc: The number of arguments passed to the program.
 * @argv: Array containing the arguments passed to the program.
 *
 * Takes two numeric strings as arguments, multiplies
 * the numbers and prints the result.
 * Return: 0 if the program executed successfully, 1 if there's an error.
 */
int main(int argc, char *argv[])
{
	char *num_str1, *num_str2;
	int total_length, i, *product, is_nonzero_found = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error_and_exit();

	num_str1 = argv[1];
	num_str2 = argv[2];

	total_length = string_length(num_str1) + string_length(num_str2) + 1;
	product = malloc(sizeof(int) * total_length);
	if (!product)
		return (1);

	for (i = 0; i <= total_length; i++)
		product[i] = 0;

	multiply_numbers(num_str1, num_str2, product);

	for (i = 0; i < total_length - 1; i++)
	{
		if (product[i])
			is_nonzero_found = 1;
		if (is_nonzero_found)
			_putchar(product[i] + '0');
	}
	if (!is_nonzero_found)
		_putchar('0');

	_putchar('\n');
	free(product);
	return (0);
}
