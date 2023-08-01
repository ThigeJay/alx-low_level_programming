#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: string to be searched
 * @accept: string containing the list of characters to match in s.
 *
 * Return: bytes number in s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				n++;
				break;
			}
			else if (accept[r + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}
