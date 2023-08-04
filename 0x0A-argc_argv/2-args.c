#include "main.h"
/**
 * main - Entry point; prints all arguments inputed,
 * @argc: Number of arguments passed.
 * @argv: Array of arguments, the first one is the program name.
 *
 * Return: 0 on success always.
 */
int main(int argc, char *argv[])
{
	int index;

	for (index = 0; index < argc; index++)
	{
		printf("%s\n", argv[index]);
	}

	return (0);
}
