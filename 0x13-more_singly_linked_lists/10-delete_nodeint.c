#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a specific
 * index in a linked list.
 * @head: double pointer to the head of the list.
 * @index: the index of the node to be deleted, starts from 0.
 *
 * Return: 1 if successfu. -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *next_node;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; current && i < index - 1; i++)
		current = current->next;

	if (!current || !(current->next))
		return (-1);

	next_node = current->next->next;
	free(current->next);
	current->next = next_node;

	return (1);
}
