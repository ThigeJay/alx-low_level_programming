#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int index = 1;
	char *c = (char *)&index;

	/* Check the least significant byte (LSB) to determine endianness */
	return (*c);
}
