#include "main.h"

/**
 * _strlen_recursion - return the lenght of the string
 * @s: string to be reversed
 * Return: int
 */

int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}
