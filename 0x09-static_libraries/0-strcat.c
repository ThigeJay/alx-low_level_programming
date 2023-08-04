#include "main.h"
/**
 * _strcat - concatenates the provided strings
 * @dest: first input string
 * @src: second input string
 *
 * Return: pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	int x;
	int y;


	x = 0;
	while (dest[x] != '\0')
	{
		x++;
	}
	y = 0;
	while (src[y] != '\0')
	{
		dest[x] = src[y];
		x++;
		y++;
	}


	dest[x] = '\0';
	return (dest);
}
