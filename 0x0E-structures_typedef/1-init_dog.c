#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Initialize the members of the 'dog' structure.
 * @d: Pointer to the 'dog' structure to be initialized.
 * @name: Name of the dog to set.
 * @age: Age of the dog to set.
 * @owner: Owner of the dog to set.
 *
 * Description: If the provided dog structure pointer 'd' is NULL,
 * it will allocate memory for a new dog structure.
 * and set dog's name, age, and owner based on the provided arguments.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
