nclude "main.h"

/**
 *  * @brief Returns the value of a bit at a given index.
 *   * 
 *    * @param n The number.
 *     * @param index The index, starting from 0 of the bit.
 *      * @return The value of the bit at index or -1 if an error occurred.
 *       */
int get_bit(unsigned long int n, unsigned int index)
{
		unsigned long int new;

			if (index >= (sizeof(unsigned long int) * 8))
						return -1;

				new = 1 << index;

					return (n & new) ? 1 : 0;
}

