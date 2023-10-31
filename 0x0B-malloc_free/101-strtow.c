#include "main.h"

/**
 *  freeg - main
 *  @grid: parameter
 *  @height: parameter
 *  return: void
 */
void freeg(char **grid, size_t height)
{
	if (grid != NULL && height != 0)
	{
		for (; height > 0 ; height--)
			free(grid[height]);
		free(grid[height]);
		free(grid);
	}
}
/**
 * strtow - splits a string into words
 * @str: string parameter
 * Return: pointer
 */

char **strtow(char *str)
{
	char **output;
	size_t c, height, i, j, n;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = height = 0 ; str[c] != '\0' ; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			height++;
	output = malloc(sizeof(char *) * (height = 1));
	if (output == NULL)
	{
		free(output);
		return (NULL);
	}
	for (i = n = 0 ; i < height ; i++)
	{
		for (c = n ; str[c] != '\0'; c++)
		{
			if (str[c] == ' ')
				n++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				output[i] = malloc((c - n + 2) * sizeof(char));
				if (output[i] == NULL)
				{
					freeg(output, i);
					return (NULL);
				}
				break;
			}
		}
		for (j = 0 ; n <= c ; n ++, j++)
			output[i][j] = str[n];
		output[i][j] = '\0';
	}
	output[i] = NULL;
	return (output);
}
