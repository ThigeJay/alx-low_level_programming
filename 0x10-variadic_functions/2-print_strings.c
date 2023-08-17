#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings followed by a new line.
 * @separator:  string to be printed.
 * @n: number of strings passed
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int counter;
	char *str;

	va_start(args, n);

	str = va_arg(args, char*);
	if (str == NULL)
		printf("(nil)");
	else
		printf("%s", str);

	for (counter = 1; counter < n; counter++)
	{
		if (separator != NULL)
			printf("%s", separator);

		str = va_arg(args, char*);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
	}

	printf("\n");
	va_end(args);
}
