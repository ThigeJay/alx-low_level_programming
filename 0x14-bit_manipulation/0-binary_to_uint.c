#include "main.h"

/**
 *binary_to_uint - Converts a binary number to an unsigned int.
 *@b: String representation of the binary.
 *
 * Return: The converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	if (!b)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		num <<= 1;
		if (b[i] == '1')
			num |= 1;
	}

	return (num);
}
