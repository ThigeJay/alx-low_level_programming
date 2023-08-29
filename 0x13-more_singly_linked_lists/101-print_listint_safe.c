#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: pointer to the head of the list.
 *
 * Return: the number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t nodes = 0;

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		nodes++;

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			exit(98);
		}
	}

	return (nodes);
}
