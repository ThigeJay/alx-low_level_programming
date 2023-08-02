#include "main.h"
/**
 * _strlen_recursion - returns string lenth
 * @s: string itself
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}

/**
 * compare - compares characters in a string
 * @s: string to be checked
 * @len: string lenght
 *
 * Return: 0 if string not a palindone. 1 i it is
 */
int compare(char *s, int len)
{
	if (len <= 1)
	{
		return (1);
	}
	else if (*s == s[len - 1])
	{
		return (compare(s + 1, len - 2));
	}
	else
	{
		return (0);
	}
}

/**
 * is_palindrome - checks for palindrone
 * @s: string to be checked
 *
 * Return: 1 if string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (compare(s, len));
}
