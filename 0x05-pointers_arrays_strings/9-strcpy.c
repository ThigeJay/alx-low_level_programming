#include "main.h"

/**
 * char *_strcpy - copies the string pointed by src
 * @dest: string to copy to
 * @src: string to copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (*(src + a) != '\0')
	{
		a++;
	}
	for ( ; b < a ; b++)
	{
		dest[b] = src[b];
	}
	dest[l] = '\0';
	return (dest);
}
