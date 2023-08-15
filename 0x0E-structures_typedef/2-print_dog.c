#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Display the details of a dog structure.
 * @d: Pointer to the dog structure to be displayed.
 *
 * Description: If a member of the dog struct is NULL,
 * it gets replaced with the string "(nil)".
 * Then it prints the name, age, and owner of the dog.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		d->name = "(nil)";
	if (d->owner == NULL)
		d->owner = "(nil)";

	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}
