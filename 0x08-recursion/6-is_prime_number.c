#include "main.h"

/**
 * prime - calculate if its prime
 * @a: input
 * @b: dividor
 * Return: 0
 */

int prime(int a, int b)
{
	if (a <= 1 || (a != b && a % b == 0))
		return (0);
	else if (a == b)
		return (1);
	return (prime(a, b + 1));
}

/**
 * is_prime_number - returns 1 if the
 * input integer is a prime number, otherwise return 0
 * @n: input integer
 * Return: 1 or 0
 */

int is_prime_number(int n)
{
	return (prime(n, 2));
}
