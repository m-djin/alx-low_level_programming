#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a linked list
 * @head: head of list
 * @index:  index of the node that should be deleted
 * Return: 1 or -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *a = NULL;
	unsigned int n = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (n < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		n++;
	}
	a = temp->next;
	temp->next = a->next;
	free(a);
	return (1);
}
