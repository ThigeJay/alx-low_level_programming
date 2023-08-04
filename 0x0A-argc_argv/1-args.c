#include "main.h"

/**
 * main - Entry;prints the number of arguments passed into it.
 * @argc: Number of arguments passed
 * @argv: Array of arguments,first one is the program name.
 *
 * Return: 0 on success always
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);

	return (0);
}
