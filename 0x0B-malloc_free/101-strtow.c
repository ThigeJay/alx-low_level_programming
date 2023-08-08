#include <stdlib.h>
#include "main.h"

/**
 * count_word - counts number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int pointer, c, word;

	pointer = 0;
	word = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			pointer = 0;
		else if (pointer == 0)
		{
			pointer = 1;
			word++;
		}
	}

	return (word);
}

/**
 * allocate_memory - allocates memory and handles errors
 * @matrix: double pointer to matrix
 * @c: length of string
 * @y: index
 *
 * Return: allocated memory
 */
char *allocate_memory(char **matrix, int c, int y)
{
	char *tmp = (char *) malloc(sizeof(char) * (c + 1));

	if (tmp == NULL)
	{
		for (int x = 0; x < y; x++) //Free previously allocated memory
			free(matrix[x]);
		free(matrix);
		return (NULL);
	}

	return tmp;
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int x, y = 0, length = 0, words, c = 0, start, end;

	while (*(str + length))
		length++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (x = 0; x <= length; x++)
	{
		if (str[x] == ' ' || str[x] == '\0')
		{
			if (c)
			{
				end = x;
				tmp = allocate_memory(matrix, c, y);
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[y] = tmp - c;
				y++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = x;
	}

	matrix[y] = NULL;

	return (matrix);
}
