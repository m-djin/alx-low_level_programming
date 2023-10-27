#include <stdio.h>

/**
 * main - program that prints its name
 * @argc: number of arguments passed
 * @argv: array of argument
 * Return: name of program and 0
 */

int main(int argc __attribute__((__unused__)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
