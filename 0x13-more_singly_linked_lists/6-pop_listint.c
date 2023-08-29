#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * and returns the head node’s data.
 * @head: double pointer to the head of the list.
 *
 * Return: data.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *tmp;

	if (!*head)
		return (0);

	data = (*head)->n;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);

	return (data);
}
