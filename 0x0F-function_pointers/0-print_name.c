#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Executes a function given as a parameter on a string argument.
 * @name: String passed as parameter to the function.
 * @f: Function to be executed on "name".
 *
 * Description:
 * If "name" or "f" is NULL, the function returns without doing anything.
 * Otherwise, it calls the function "f" with "name" as an argument.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
