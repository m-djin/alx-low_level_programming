#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: string parameter to be copied
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	int i;
	char *copy;
	int count;

	if (str ==NULL)
		return ('\0');
	for (i = 0 ; str[i] != '\0'; i++)
		count++;
	copy = malloc((sizeof(char) *  count) + 1);

	if (copy == NULL)
		return ('\0');
	for (i = 0 ; str[i] != '\0' ; i++)
		copy[i] = str[i];
	return (copy);
}
