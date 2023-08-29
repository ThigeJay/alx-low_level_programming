#include "lists.h"

/**
 * free_listint_safe - Safely frees a linked list that might
 * contain loops.
 * @h: Double pointer to the head of the linked list.
 *
 * Return: Number of nodes in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_count = 0;
	ptrdiff_t offset;
	listint_t *next_node;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		offset = *h - (*h)->next;
		if (offset > 0)
		{
			next_node = (*h)->next;
			free(*h);
			*h = next_node;
			node_count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			node_count++;
			break;
		}
	}

	*h = NULL;

	return (node_count);
}
