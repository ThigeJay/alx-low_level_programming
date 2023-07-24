#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string that needs converting
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int a, b, n, length, x, number;

	a = 0;
	b = 0;
	n = 0;
	length = 0;
	x = 0;
	number = 0;

	while (s[length] != '\0')
		length++;

	while (a < length && f == 0)
	{
		if (s[a] == '-')
			++b;

		if (s[a] >= '0' && s[a] <= '9')
		{
			number = s[a] - '0';
			if (b % 2)
				number = -number;
			n = n * 10 + number;
			x = 1;
			if (s[a + 1] < '0' || s[a + 1] > '9')
				break;
			x = 0;
		}
		a++;
	}

	if (x == 0)
		return (0);

	return (n);
}
