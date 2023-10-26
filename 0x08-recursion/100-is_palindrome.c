#include "main.h"

/**
 * _strlen_recursion - find lenght of string
 * @s: string input
 * Return: lenght of the string
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));
}

/**
 * compare - compare char in string
 * @s: string
 * @left: smallest
 * @right: largest
 * Return: int
 */

int compare(char *s, int left, int right)
{
	if (*(s + left) == *(s + right))
	{
		if (left == right || left == right + 1)
			return (1);
		return (0 + compare(s, left + 1, right - 1));
	}
	return (0);
}

/**
 * is_palindrome -  returns 1 if a string is a
 * palindrome and 0 if not
 * @s: string input
 * Return: 1 or 0
 */

int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (compare(s, 0, _strlen_recursion(s) - 1));
}
