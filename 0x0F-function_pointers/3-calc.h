#ifndef CALC_H
#define CALC_H

/**
 * struct op - Structure to map operator with its function.
 * @op: The operator (string representation).
 * @f: Function pointer to the corresponding operation.
 *
 * Description:
 * Each operator is linked with its corresponding function.
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

/* Function prototypes for operations */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/* Function prototype to get the correct operation function */
int (*get_op_func(char *s))(int, int);

#endif
