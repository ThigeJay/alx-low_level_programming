#include "main.h"
#include <stdlib.h>
/**
 * argstostr - main entry
 * @ac: int input
 * @av: double pointer array
 * Return: 0
 */
char *argstostr(int ac, char **av)
{
	int argument, argument2, argument3 = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (argument = 0; argument < ac; argument++)
	{
		for (argument2 = 0; av[argument][argument2]; argument2++)
			l++;
	}
	l += ac;

	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);
	for (argument = 0; argument < ac; argument++)
	{
	for (argument2 = 0; av[argument][argument2]; argument2++)
	{
		str[argument3] = av[argument][argument2];
		argument3++;
	}
	if (str[argument3] == '\0')
	{
		str[argument3++] = '\n';
	}
	}
	return (str);
}
