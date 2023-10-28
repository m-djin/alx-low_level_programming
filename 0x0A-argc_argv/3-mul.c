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
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
