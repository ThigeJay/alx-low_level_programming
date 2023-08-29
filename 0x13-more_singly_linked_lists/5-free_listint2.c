#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list then sets the head to NULL.
 * @head: double pointer to the head of the list.
 *
 * Return: Nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (!head)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}
