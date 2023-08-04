#include <stdio.h>
#include "main.h"

/**
 * main - start point of the program,prints path.
 * @argc: Number of arguments. The compiler is informed that this is unused.
 * @argv: Array of arguments, where the first is the program name.
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
