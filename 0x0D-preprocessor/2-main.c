#include <stdio.h>

/**
 * main - Entry point of the program.
 *        Prints the name of the source file being compiled.
 *
 * __FILE__: predefined macro in C used to print the current file name.
 *
 * Return: 0 if the program executed successfully.
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
