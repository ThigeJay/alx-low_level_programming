#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Description: A program that prints the opcodes of its main function.
 *
 * Return: 0 on success, 1 or 2 on error (based on the task requirements).
 */
int main(int argc, char *argv[])
{
	int numOfBytes, index;
	char *opcodePointer;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	numOfBytes = atoi(argv[1]);

	if (numOfBytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	opcodePointer = (char *)main;

	for (index = 0; index < numOfBytes; index++)
	{
		/* Print in hexadecimal format */
		printf("%02hhx", opcodePointer[index]);
		/* If it's not the last byte, print a space */
		if (index < numOfBytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
