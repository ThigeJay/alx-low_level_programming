nclude "main.h"

/**
 *  * @brief Sets the value of a bit to 1 at a given index.
 *   * 
 *    * @param n Pointer to the number.
 *     * @param index The index, starting from 0 of the bit to set.
 *      * @return 1 if it worked, or -1 if an error occurred.
 *       */
int set_bit(unsigned long int *n, unsigned int index)
{
		if (index >= (sizeof(unsigned long int) * 8))
					return -1;

			*n |= (1 << index);

				return 1;
}

