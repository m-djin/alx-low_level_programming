#include <stdio.h>
#include <stdlib.h>

/**
 * main - multplies two numbers
 * @argc: integer passed
 * @argv: array of strings to be passed
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	int i, acc = 0;

	if (argc > 1)
	{
		for (i = 1 ; i < argc ; i++)
		{
			acc = atoi(argv[1]) * atoi(argv[2]);
		}
		printf("%d\n", acc);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
