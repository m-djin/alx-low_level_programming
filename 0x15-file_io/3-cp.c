#include "main.h"

void check_io(int stat, int fl, char *filename, char mode);

/**
 * main - copies the content of a file to another file
 * @argv: number of argument
 * @argc: argumnets passed
 * Return: 1
 */

int  main(int argc, char *argv[])
{
	char buff[1024];
	int src, dest, down, end_src, end_dest, count = 1024;
	unsigned int app = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(argv[1], O_RDONLY);
	check_io(src, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, app);
	check_io(dest, -1, argv[2], 'W');
	while (count == 1024)
	{
		count = read(src, buff, sizeof(buff));
		if (count == -1)
			check_io(-1, -1, argv[1], 'O');
		down = write(dest, buff, count);

		if (down == -1)
			check_io(-1, -1, argv[2], 'W');
	}
	end_src = close(src);
	check_io(end_src, src, NULL, 'C');
	end_dest = close(dest);
	check_io(end_dest, dest, NULL, 'C');
	return (0);
}

/**
 * check_io - check whether or not the file is opened
 * @stat: file description
 * @filename: name of the file
 * @mode: closed or otherwisw
 * @fl: file descriptor
 * Return: void
 */

void check_io(int stat, int fl, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fl);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
