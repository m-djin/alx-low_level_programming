#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: head of the list
 * Return: number of element in the list
 */

size_t listint_len(const listint_t *h)
{
	size_t c;

	if (h == NULL)
		return (0);
	for (c = 0 ; h != NULL ; c++)
		h = h->next;
	return (c);
}
