#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings followed by a new line.
 * @delimiter: string to separate the output values.
 * @numStrings: number of strings passed as arguments.
 */
void print_strings(const char *delimiter, const unsigned int numStrings, ...)
{
	va_list stringList;
	unsigned int currentIndex;
	char *currentString;

	va_start(stringList, numStrings);

	currentString = va_arg(stringList, char*);
	if (currentString == NULL)
		printf("(nil)");
	else
		printf("%s", currentString);

	for (currentIndex = 1; currentIndex < numStrings; currentIndex++)
	{
		if (delimiter != NULL)
			printf("%s", delimiter);

		currentString = va_arg(stringList, char*);
		if (currentString == NULL)
			printf("(nil)");
		else
			printf("%s", currentString);
	}

	printf("\n");
	va_end(stringList);
}
