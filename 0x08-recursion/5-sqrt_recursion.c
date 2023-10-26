#include "main.h"

/**
 * square_root - return the natural square root
 * @a: input
 * @b: iterator
 * Return: squared or -1
 */

int square_root(int a, int b)
{
	if (b * b == a)
		return (b);
	else if (b * b > a)
		return (-1);
	return (square_root(a, b + 1));
}
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: given number
 * Return: natural square root
 */

int _sqrt_recursion(int n)
{
	return (square_root(n, 0));
}
