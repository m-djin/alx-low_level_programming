#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 char
 * Return: converted number or 0
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i;
	int n;

	i = 0;

	if (!b)
		return (0);
	for (n = 0 ; b[n] != '\0' ; n++)
	{
		if (b[n] != '0' && b[n] != '1')
			return (0);
	}
	for (n = 0 ; b[n] != '\0' ; n++)
	{
		i <<= 1;
		if (b[n] == '1')
			i++;
	}
	return (i);
}
