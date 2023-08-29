#include "lists.h"
#include <stdio.h>

size_t find_loop(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * find_loop - Identifies the node where a loop starts in a linked list
 *             using Floyd's cycle algorithm.
 * @head: A pointer to the head of the list to check.
 *
 * Return: If there's no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
const listint_t *find_loop(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
			return (tortoise);
	}

	return (NULL);
}

/**
 * print_listint_safe - Safely prints a listint_t list.
 * @head: A pointer to the head of the listint_t list to print.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *loop_start;

	loop_start = find_loop(head);

	if (!loop_start)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			nodes++;
		}
	}
	else
	{
		while (head != loop_start)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			nodes++;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
		nodes++;
	}

	return (nodes);
}
