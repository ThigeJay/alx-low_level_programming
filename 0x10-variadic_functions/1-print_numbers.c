#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers followed by a new line.
 * @separator: string to be printed between numbers.
 * @n: number of integers.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbersList;
	unsigned int currentIndex;

	va_start(numbersList, n);

	if (n > 0)
		printf("%d", va_arg(numbersList, int));

	for (currentIndex = 1; currentIndex < n; currentIndex++)
	{
		if (separator != NULL)
			printf("%s", separator);
		printf("%d", va_arg(numbersList, int));
	}

	printf("\n");
	va_end(numbersList);
}
