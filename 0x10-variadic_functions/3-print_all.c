#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints various data types based on the format provided.
 * @formatSpecifier: list of types of arguments passed.
 */
void print_all(const char * const formatSpecifier, ...)
{
	va_list listOfArguments;
	int index = 0;
	char *separator = "";
	char *currentString;

	va_start(listOfArguments, formatSpecifier);

	while (formatSpecifier && formatSpecifier[index])
	{
		switch (formatSpecifier[index])
		{
			case 'c':
				printf("%s%c", separator, va_arg(listOfArguments, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(listOfArguments, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(listOfArguments, double));
				break;
			case 's':
				currentString = va_arg(listOfArguments, char *);
				if (!currentString)
					currentString = "(nil)";
				printf("%s%s", separator, currentString);
				break;
			default:
				index++;
				continue;
		}
		separator = ", ";
		index++;
	}

	printf("\n");
	va_end(listOfArguments);
}
