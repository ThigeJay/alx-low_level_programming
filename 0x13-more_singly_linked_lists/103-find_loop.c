#include "lists.h"

/**
 * find_listint_loop - Detects a loop in a linked list using
 * Floyd's cycle-finding algorithm.
 * @head: Head of the linked list.
 *
 * Return: Address of the node where the loop starts.
 * NULL if no loop found.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head;
	listint_t *hare = head;

	if (!head)
		return (NULL);

	while (tortoise && hare && hare->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;

		if (hare == tortoise)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (hare);
		}
	}

	return (NULL);
}
