#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - Determines the function associated with an operator.
 * @s: The operator to match.
 *
 * Description:
 * Matches the provided operator with the correct function.
 *
 * Return: Pointer tofunction that corresponds to the matched operator.
 *         If no match is found, returns NULL.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};

	int index = 0;

	while (ops[index].op && *ops[index].op != *s)
		index++;

	return (ops[index].f);
}
