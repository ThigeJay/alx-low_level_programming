#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data ina listint_t list.
 * @head: head of list pointer.
 *
 * Return: sum of all the data in the list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
