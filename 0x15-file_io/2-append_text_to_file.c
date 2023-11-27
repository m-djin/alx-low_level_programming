#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename:  name of the file
 * @text_content: string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fl, lts, _rw;

	if (!filename)
		return (-1);

	fl = open(filename, O_WRONLY | O_APPEND);
	if (fl == -1)
		return (-1);
	if (text_content)
	{
		for (lts =  0 ; text_content[lts]; lts++)
			;
		_rw = write(fl, text_content, lts);
		if (_rw == -1)
			return (-1);
	}
	close(fl);

	return (1);
}
