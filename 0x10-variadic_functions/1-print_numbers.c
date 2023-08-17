#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers followed by a new line.
 * @separator: string to be printed between numbers.
 * @n: integers number.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int counter;

	va_start(args, n);

	if (n > 0)
		printf("%d", va_arg(args, int));

	for (counter = 1; counter < n; counter++)
	{
		if (separator != NULL)
			printf("%s", separator);
		printf("%d", va_arg(args, int));
	}

	printf("\n");
	va_end(args);
}
