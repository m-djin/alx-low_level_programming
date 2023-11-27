#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of file to be read
 * @letters: number of letters
 * Return: the actual number of letters it could read and print
 * Or 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int filed;
	ssize_t lr, lw;
	char *buff;

	if (filename == NULL)
		return (0);
	filed = open(filename, O_RDONLY);
	if (filed == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(filed);
		return (0);
	}
	lr = read(filed, buff, letters);
	close(filed);
	if (lr == -1)
	{
		free(buff);
		return (0);
	}
	lw = write(STDOUT_FILENO, buff, lr);
	free(buff);
	if (lr != lw)
		return (0);
	return (lw);
}
