#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Releases memory associated with a dog structure.
 * @d: Pointer to the dog structure to be freed.
 *
 * Description: frees up the memory allocated for the members
 * (name, owner) of the dog structure and then the structure itself.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
