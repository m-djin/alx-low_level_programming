#include "main.h"

#define ERR_MSG "Error"

/**
 * is_num - check if a string contains character
 * @s: string parameter
 * Return: 0 or 1
 */

int is_num(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - checks the lenght of a string
 * @s: string parameter
 * Return: lenght of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * errors - handle the error
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiply two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, carry, num1, num2, *result, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_num(s1) || !is_num(s2))
		errors();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0 ; i <= len1 + len2 ; i++)
		result[i] = 0;
	for (len1 = len1 - 1 ; len1 >= 0 ; len1--)
	{
		num1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1 ; len2 >= 0 ; len2--)
		{
			num2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (num1 * num2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0 ; i < len - 1 ; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
