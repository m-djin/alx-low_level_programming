#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another
 * @n: first parameter
 * @m: second parameter
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count;
	unsigned long int arr, ext = n ^ m;

	count = 0;
	for (x = 63 ; x >= 0 ; x--)
	{
		arr = ext >> x;
		if (arr & 1)
			count++;
	}
	return (count);
}
