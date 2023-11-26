#include "main.h"

/**
 * flip_bits - Calculates the number of bits to flip.
 *
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* Calculate the bitwise XOR of the two numbers */
	unsigned long int xor_result = n ^ m;

	/* Count the number of set bits (1s) in the XOR result */
	unsigned int bit_count = 0;

	/* Iterate through each bit in the XOR result */
	while (xor_result)
	{
		/* Increment the count for each set bit */
		bit_count += (xor_result & 1);

		/* Right-shift to check the next bit */
		xor_result >>= 1;
	}

	/* Return the total count of set bits (flipped bits) */
	return (bit_count);
}
