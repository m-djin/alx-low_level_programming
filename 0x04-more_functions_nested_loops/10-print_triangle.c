#include "main.h"

/**
 * print_triangle -  prints a triangle
 * @size: size of triangle
 * Return: void
 */

void print_triangle(int size)
{
	int i, j, t;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1 ; i <= size ; i++)
		{
			for (t = size - i ; t >= 1 ; t--)
			{
				_putchar(' ');
			}
			for (j = 1 ; j <= i ; j++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
