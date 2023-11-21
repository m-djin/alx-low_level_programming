#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a list
 * @head: first node int list
 * Return:  returns the sum of all the data or 0
 */

int sum_listint(listint_t *head)
{
	int total = 0;
	listint_t *temp =  head;

	while (temp)
	{
		total += temp->n;
		temp = temp->next;
	}
	return (total);
}
