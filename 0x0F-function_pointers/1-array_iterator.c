#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - executes afunction on each element
 * @array: the array
 * @size: size of array
 * @action: function to be executed on each element
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0 ; i < size ; i++)
		action(array[i]);
}
