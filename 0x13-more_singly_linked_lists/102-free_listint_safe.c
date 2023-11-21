#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: first node of lisr
 * Return: size of the list that was free’d
 */

size_t free_listint_safe(listint_t **h)
{
	size_t l = 0;
	int less;
	listint_t *temp;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		less = *h - (*h)->next;
		if (less > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}
	*h = NULL;
	return (l);
}
