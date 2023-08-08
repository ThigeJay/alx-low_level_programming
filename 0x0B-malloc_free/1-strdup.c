#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates a string by allocating a new block of memory
 * @str: the string to be duplicated
 *
 * This function duplicates a given string by allocating a new block of memory.
 * If the input string is NULL or if memory allocation fails, it returns NULL.
 * Otherwise, returns a pointer to the duplicated string.
 *
 * Return: a pointer to the duplicated string if successful, NULL if it fails
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int length, index;

	if (str == NULL)
		return (NULL);

	length = 0;
	while (str[length] != '\0')
		length++;

	duplicate_str = malloc(sizeof(char) * (length + 1));

	if (duplicate_str == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		duplicate_str[index] = str[index];

	return (duplicate_str);
}
