#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates up to n bytes from string s2 to string s1.
 * @s1: The primary string to which the other string will be concatenated.
 * @s2: The string to concatenate up to n bytes from.
 * @n: Max number of bytes from s2 to concatenate to s1.
 * If n is greater or equal to the length of s2,use string s2.
 * If one of the strings is NULL,treat it as empty string.
 *
 * Return: A pointer to the newly allocated space
 *  returns NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result_str;
	unsigned int len_s1 = 0, len_s2 = 0, idx = 0, s2_idx = 0;

	/*Determine the lengths of the input strings.*/
	while (s1 && s1[len_s1])
		len_s1++;
	while (s2 && s2[len_s2])
		len_s2++;

	/*Allocate the required memory for the concatenated string.*/
	if (n < len_s2)
		result_str = malloc(sizeof(char) * (len_s1 + n + 1));
	else
		result_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));

	if (!result_str)
		return (NULL);

	/*Copy s1 to the resulting string.*/
	while (idx < len_s1)
	{
		result_str[idx] = s1[idx];
		idx++;
	}

	if (n < len_s2)
		while (s2_idx < n)
			result_str[idx++] = s2[s2_idx++];
	else
		while (s2_idx < len_s2)
			result_str[idx++] = s2[s2_idx++];

	result_str[idx] = '\0';

	return (result_str);
}
