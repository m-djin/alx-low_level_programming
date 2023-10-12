#include "main.h"

/**
 * _isupper - check uppercase letters
 * @c: function parameter
 * Return: 1 if successful but 0 if not
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}
