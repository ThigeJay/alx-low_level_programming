#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * str_len - Computes the length of a string.
 * @str: The string whose length is to be computed.
 *
 * Return: Length of the string.
 */
unsigned int str_len(const char *str)
{
	unsigned int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the list_t list.
 * @str: String to add in the new node.
 *
 * Return: Address of the new element, or NULL if it fails.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *last_node = *head;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = str_len(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (last_node->next)
		last_node = last_node->next;

	last_node->next = new_node;

	return (new_node);
}
