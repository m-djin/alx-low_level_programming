#include "main.h"

/**
 * _realloc -  reallocates a memory block using malloc and free
 * @ptr:pointer to the memory previously allocated with a call to malloc
 * @old_size: allocated space for ptr
 * @new_size: new memory block
 * Return: ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *out;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		out = malloc(new_size);
		if (out == NULL)
			return (NULL);
		return (out);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}
	out = malloc(new_size);
	if (out == NULL)
		return (NULL);
	for (i = 0 ; i < old_size && i < new_size ; i++)
		out[i] = ((char *) ptr)[i];
	free(ptr);
	return (out);
}
