#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: function parameter to swapped
 * @b: second parameter to be swapped
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int m;

	m = *a;
	*a = *b;
	*b = m;
}
