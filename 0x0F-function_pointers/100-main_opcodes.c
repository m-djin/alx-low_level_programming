#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc:number of arguments
 * @argv: array arguments
 * Return: void
 */

int main(int argc, char *argv[])
{
	int i, b;
	int (*address)(int, char **) =  main;
	unsigned char output;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	b = atoi(argv[1]);

	if (b < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0 ; i < b ; i++)
	{
		output =  *(unsigned char *)address;
		printf("%.2x", output);

		if (i == b - 1)
			continue;
		printf(" ");
		address++;
	}
	printf("\n");
	return (0);
}
