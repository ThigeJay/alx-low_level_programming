#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * This function concatenates two strings by creating a new string,
 * allocating enough memory to hold both input strings and a null terminator.
 * If either of the input strings is NULL, it treats it as an empty string.
 * If memory allocation fails, it returns NULL.
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int len_s1, len_s2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len_s1 = len_s2 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	while (s2[len_s2] != '\0')
		len_s2++;
	concat_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));

	if (concat_str == NULL)
		return (NULL);
	len_s1 = len_s2 = 0;
	while (s1[len_s1] != '\0')
	{
		concat_str[len_s1] = s1[len_s1];
		len_s1++;
	}

	while (s2[len_s2] != '\0')
	{
		concat_str[len_s1] = s2[len_s2];
		len_s1++, len_s2++;
	}
	concat_str[len_s1] = '\0';
	return (concat_str);
}
