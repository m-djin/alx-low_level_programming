#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list
 * Return: address of the node where the loop starts or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *strt = head, *finish = head;

	if (!head)
		return (NULL);
	while (strt && finish && finish->next)
	{
		finish = finish->next->next;
		strt = strt->next;
		if (finish == strt)
		{
			strt = head;
			while (strt != finish)
			{
				strt = strt->next;
				finish = finish->next;
			}
			return (finish);
		}
	}
	return (NULL);
}
