#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Counts and returns the number of nodes in a linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Description: atraverses the entire linked list, counting each node until
 * it reaches the end.
 *
 * Return: Total number of nodes in the linked list.
 */
size_t list_len(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		node_count++;
		h = h->next;
	}

	return (node_count);
}
