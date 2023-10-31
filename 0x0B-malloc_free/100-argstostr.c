#include "main.h"

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: number of argument
 * @av: array of string
 * Return: pointer
 */

char *argstostr(int ac, char **av)
{
	char *out;
	int i, j;
	int a = 0, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac ; i++)
	{
		for (j = 0; av[i][j] ; j++)
			len++;
	}
	len += ac;
	out = malloc(sizeof(char) * len + 1);
	if (out == NULL)
		return (NULL);
	for (i = 0 ; i < ac; i++)
	{
		for (j = 0 ; av[i][j] ; j++)
		{
			out[a] = av[i][j];
			a++;
		}
		if (out[a] == '\0')
		{
			out[a++] = '\n';
		}
	}
	return (out);
}
