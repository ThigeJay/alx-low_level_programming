#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 * @head: pointer to the head of the list.
 *
 * Return: Nothing.
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
