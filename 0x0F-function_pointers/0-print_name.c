#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a given name using the provided function pointer.
 * @name: The name (string) to be printed.
 * @f: A pointer to a function that handles the printing mechanism.
 *
 * Description: The function early - returns if either 'name' or the function pointer 'f' is NULL.
 * Return: None/void
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
