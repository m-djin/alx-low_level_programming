#include "main.h"

/**
 * char *_memcpy - copies memory area
 * @dest: destination of copied area
 * @src: src of bytes from memory
 * @n: no of copies
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
