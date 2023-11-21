#include "lists.h"

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - track the number of unique nodes
 * @head: head of list
 * Return: number of nodes
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *t, *h;
	size_t new = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	t = head->next;
	h = (head->next)->next;

	while (h)
	{
		if (t == h)
		{
			t = head;
			while (t != h)
			{
				new++;
				t = t->next;
				h = h->next;
			}
			t = t->next;
			while (t != h)
			{
				new++;
				t = t->next;
			}
			return (new);
		}
		t = t->next;
		h = (h->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: head of list
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t new, ind = 0;

	new = looped_listint_len(head);
	if (new == 0)
	{
		for (; head != NULL; new++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (ind = 0 ; ind < new ; ind++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (new);
}
