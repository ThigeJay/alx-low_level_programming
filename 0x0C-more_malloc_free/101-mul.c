#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * contains_only_digits - Check if a string consists
 * solely of digit characters.
 * @str: The string to check.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int contains_only_digits(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * string_length - Computes the length of a string.
 * @str: The string to measure.
 *
 * Return: The length of the string.
 */
int string_length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * print_error_and_exit - Print an error message and then exit the program.
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply_numbers - Multiplies two positive numbers represented as strings.
 * @num1: First number as a string.
 * @num2: Second number as a string.
 * @product: Resultant product array.
 */
void multiply_numbers(char *num1, char *num2, int *product)
{
	int len1, len2, carry, digit1, digit2, i;

	len1 = string_length(num1);
	len2 = string_length(num2);

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1[len1] - '0';
		carry = 0;
		for (len2 = string_length(num2) - 1; len2 >= 0; len2--)
		{
			digit2 = num2[len2] - '0';
			carry += product[len1 + len2 + 1] + (digit1 * digit2);
			product[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			product[len1 + len2 + 1] += carry;
	}
}

/**
 * main - Entry point. Multiplies two positive numbers passed as strings.
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int total_len, i, *product, has_printed_digit = 0;

	if (argc != 3 || !contains_only_digits(argv[1]) ||
	!contains_only_digits(argv[2]))
		print_error_and_exit();

	num1 = argv[1];
	num2 = argv[2];

	total_len = string_length(num1) + string_length(num2) + 1;
	product = malloc(sizeof(int) * total_len);
	if (!product)
		return (1);

	for (i = 0; i <= total_len; i++)
		product[i] = 0;

	multiply_numbers(num1, num2, product);

	for (i = 0; i < total_len - 1; i++)
	{
		if (product[i])
			has_printed_digit = 1;
		if (has_printed_digit)
			_putchar(product[i] + '0');
	}
	if (!has_printed_digit)
		_putchar('0');

	_putchar('\n');
	free(product);
	return (0);
}
