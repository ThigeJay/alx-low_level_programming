#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be scanned.
 * @accept: The string containing the list of characters to match in s.
 *
 * Return: The number of bytes in s which consist only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int scan = 0;
	int index;

	while (*s)
	{
		for (r = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				scan++;
				break;
			}
			else if (accept[index + 1] == '\0')
				return (scan);
		}
		s++;
	}
	return (scan);
}

