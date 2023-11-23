#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: 0 if big endian 1 if little endian
 */

int get_endianness(void)
{
	char *v;
	int x = 1;

	v = (char *)&x;
	return (*v);
}
