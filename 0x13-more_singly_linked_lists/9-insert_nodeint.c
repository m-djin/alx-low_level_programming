#include "lists.h"

/**
 * insert_nodeint_at_index -  inserts a new node at a given position
 * @head: head of the list
 * @idx: index for new node to be added
 * @n: data to be added
 * Return: address of the new node or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int c;
	listint_t *new_node, *temp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	for (c = 0 ; temp && c < idx ; c++)
	{
		if (c == idx - 1)
		{
			new_node->next = temp->next;
			temp->next = new_node;
			return (new_node);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
