#include "lists.h"
#include <stdio.h>

const listint_t *find_start_of_loop(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * find_start_of_loop - Detects the start node of a loop in a linked list using Floyd's cycle-finding algorithm.
 * @head: A pointer to the head of the list to check.
 *
 * Return: A pointer to the start of the loop, or NULL if there's no loop.
 */
const listint_t *find_start_of_loop(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (tortoise);
		}
	}

	return (NULL);
}

/**
 * print_listint_safe - Safely prints a listint_t list that can have loops.
 * @head: A pointer to the head of the listint_t list to print.
 *
 * Return: The number of nodes printed.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *loop_start;

	loop_start = find_start_of_loop(head);

	while (head && (head != loop_start || nodes == 0))
	{
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;
		head = head->next;

		if (head == loop_start && nodes != 0)
			printf("-> [%p] %d\n", (void *)head, head->n);
	}

	if (!head)
		exit(98);

	return (nodes);
}
