#include "main.h"

/**
 * _strncpy - Copies up to 'n' characters from source string
 * to destination string
 * @dest: Destination string to copy into
 * @src: Source string to copy from
 * @n: Maximum number of characters to be copied from source
 *
 * Return: Pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int y;

	y = 0;
	while (y < n && src[y] != '\0')
	{
		dest[y] = src[y];
		y++;
	}
	while (y < n)
	{
		dest[y] = '\0';
		y++;
	}

	return (dest);
}
