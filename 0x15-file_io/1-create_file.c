#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: string to write to the file
 * Return: 1 on success and -1 in fail
 */

int create_file(const char *filename, char *text_content)
{
	int fl, lts, _rw;

	if (!filename)
		return (-1);

	fl = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 600);
	if (fl == -1)
		return (-1);
	if (!text_content)
		text_content = "";
	for (lts = 0 ; text_content[lts]; lts++)

	_rw = write(fl, text_content, lts);
	if (_rw == -1)
		return (-1);
	close(fl);
	return (1);
}
