#include "main.h"
/**
 * wildcmp - compares 2 strings and returns 1 if
 * the strings can be considered identical.
 * Else,return 0
 * @s1: string to compare
 * @s2: another string to compare which
 * might contain the special character *
 *
 * Return: 1 if the strings are identical, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		if (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)))
		{
			return (1);
		}
	}
	return (0);
}
