#include "main.h"

/**
 * rev_string -  function that reverses a string.
 * @s: Input string
 * Return: the string in reverse mode
 */

void rev_string(char *s)
{
	char rev = s[0];
	intnumber = 0;
	int i;

	while (s[number] != '\0')
	counter++;
	for (i = 0; i <number; i++)
	{
		number--;
		rev = s[i];
		s[i] = s[number];
		s[number] = rev;
	}
}
