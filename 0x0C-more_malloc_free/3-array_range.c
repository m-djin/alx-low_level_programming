#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: input parameter
 * @max: input parameter
 * Return: pointer or NULL
 */

int *array_range(int min, int max)
{
	int *output, i;

	if (min > max)
		return (NULL);
	output = malloc((sizeof(int) * (max - min)) + sizeof(int));
	if (output == NULL)
		return (NULL);
	for (i = 0 ; min <= max ; i++)
	{
		output[i] = min;
		min++;
	}
	return (output);
}
