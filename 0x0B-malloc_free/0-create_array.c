#include "main.h"

/**
 * create_array - creates an array of chars
 * and initializes it with a specific char
 * @size: size of array
 * @c: character to store in array
 * Return: pointer to th array
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *a;

	if (size == 0)
		return ('\0');
	a = malloc(sizeof(char) * size);

	if (a == NULL)
		return ('\0');
	for (i = 0 ; i < size ; i++)
		a[i] = c;
	return (a);
}
