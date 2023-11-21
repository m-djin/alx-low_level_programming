#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a linked list
 * @head: first node in a list
 * @index: index of the node
 * Return: returns the nth node or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int ind = 0;
	listint_t *temp = head;

	while (temp && ind < index)
	{
		temp = temp->next;
		ind++;
	}

	return (temp ? temp : NULL);
}
