#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * h: the head of the list
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t c;

	if (h == NULL)
		return (0);
	for (c =  0 ; h != NULL ;  c++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (c);
}
