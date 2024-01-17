#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: head of list
 * @index: index of a dlistint_t
 * Return: 1 or -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *l1, *l2;
	unsigned int x;

	l1 = *head;
	if (l1 != NULL)
		while (l1->prev != NULL)
			l1 = l1->prev;
	x = 0;

	while (l1 != NULL)
	{
		if (x == index)
		{
			if (x == 0)
			{
				*head = l1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				l2->next = l1->next;

				if (l1->next != NULL)
					l1->next->prev = l2;
			}
			free(l1);
			return (1);
		}
		l2 = l1;
		l1 = l1->next;
		x++;
	}
	return (-1);
}
