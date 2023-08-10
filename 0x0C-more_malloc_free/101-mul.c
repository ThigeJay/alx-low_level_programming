#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - Check if a string consists only of numerals
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
 * _strlen - Compute the length of a string.
 * @str: The string whose length is to be determined.
 *
 * Return: The number of characters in the string
 * (excluding the terminating NULL character).
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * errors - Prints an error message and exits the program.
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - Multiplies two positive numbers represented as strings.
 * @argc: The number of arguments passed to the program.
 * @argv: Array containing the arguments passed to the program.
 *
 * takes 2 numeric strings as arguments, multiplies
 * them and prints the result.
 * If the arguments are not numeric,strings or
 * not exactly two arguments, prints an error message.
 *
 * Return: 0 if the program executed successfully, 1 if there's an error.
 */
int main(int argc, char *argv[])
{
	char *num_str1, *num_str2;
	int len_str1, len_str2, total_length, idx, carry,
	num1_digit, num2_digit, *product, is_nonzero_found = 0;

	num_str1 = argv[1];
	num_str2 = argv[2];

	if (argc != 3 || !is_digit(num_str1) || !is_digit(num_str2))
		errors();

	len_str1 = _strlen(num_str1);
	len_str2 = _strlen(num_str2);
	total_length = len_str1 + len_str2 + 1;

	product = malloc(sizeof(int) * total_length);
	if (!product)
		return (1);

	for (idx = 0; idx <= len_str1 + len_str2; idx++)
		product[idx] = 0;

	for (len_str1 = len_str1 - 1; len_str1 >= 0; len_str1--)
	{
		num1_digit = num_str1[len_str1] - '0';
		carry = 0;
		for (len_str2 = _strlen(num_str2) - 1; len_str2 >= 0; len_str2--)
		{
			num2_digit = num_str2[len_str2] - '0';
			carry += product[len_str1 + len_str2 + 1] + (num1_digit * num2_digit);
			product[len_str1 + len_str2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			product[len_str1 + len_str2 + 1] += carry;
	}

	for (idx = 0; idx < total_length - 1; idx++)
	{
		if (product[idx])
			is_nonzero_found = 1;
		if (is_nonzero_found)
			_putchar(product[idx] + '0');
	}
	if (!is_nonzero_found)
		_putchar('0');

	_putchar('\n');
	free(product);
	return (0);
}
