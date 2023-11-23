#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: value to set
 * @index: index bit you want to set at
 * Return: 1 0r -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
