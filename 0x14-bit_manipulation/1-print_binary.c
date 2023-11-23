#include "main.h"

/**
 * pw - calculates base power
 * @base: base
 * @power: exponent
 * Return: value of base and power
 */

unsigned long int pw(unsigned int base, unsigned int power)
{
	unsigned long int i = 1;
	unsigned int x;

	for (x =  1 ; x <= power ; x++)
		i *= base;
	return (i);
}

/**
 * print_binary - prints the binary representation
 * @n: number input
 * Return: void
 */

void print_binary(unsigned long int n)
{
	char indi = 0;
	unsigned long int div, scan;

	div = pw(2, sizeof(unsigned long int) * 8 - 1);
	while (div != 0)
	{
		scan = n & div;
		if (scan == div)
		{
			indi = 1;
			_putchar('1');
		}
		else if (indi == 1 || div == 1)
		{
			_putchar('0');
		}
		div >>= 1;
	}
}
