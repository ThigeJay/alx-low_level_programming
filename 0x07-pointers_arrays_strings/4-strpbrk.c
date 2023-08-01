#include "main.h"

/**
 * _strpbrk - search the string for any of a set of bytes.
 * @s: string to be searched.
 * @accept: set of bytes
 *
 * Return: pointer to the matched byte,NULL If no set is matched.
 */
char *_strpbrk(char *s, char *accept)
{
		int jay;

		while (*s)
		{
			for (jay = 0; accept[jay]; jay++)
			{
			if (*s == accept[jay])
			return (s);
			}
		s++;
		}

	return ('\0');
}
