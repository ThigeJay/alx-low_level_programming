nclude "main.h"

/**
 *  * @brief Checks the endianness of the system.
 *   * 
 *    * @return 0 if big endian, 1 if little endian.
 *     */
int get_endianness(void)
{
		unsigned int index = 1;
			char *c = (char *) &index;

				return (*c);
}

