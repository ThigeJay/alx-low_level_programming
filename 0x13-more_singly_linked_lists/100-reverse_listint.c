#include "lists.h"

/**
 * reverse_listint - Reverses the given linked list.
 * @head: Double pointer to the head of the linked list.
 *
 * Description:
 * This function iterates through the given linked list, reversing the
 * order of the nodes. It does this by keeping track of the previous
 * node and next node while adjusting the current node's next pointer
 * to point to the previous node.
 *
 * Return: Pointer to the head of the reversed linked list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous_node = NULL;
	listint_t *next_node = NULL;

	while (*head)
	{
		next_node = (*head)->next;

		(*head)->next = previous_node;

		previous_node = *head;
		*head = next_node;
	}

	*head = previous_node;

	return (*head);
}
