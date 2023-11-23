#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: value of bits input
 * @index: the bit you want to get
 * Return: value of the bit at index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div, scan;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << index;
	scan = n & div;
	if (scan == div)
		return (1);
	return (0);
}
