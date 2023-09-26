#include "main.h"
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: NULL terminated string to be appended.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	while (text_content[len])
		len++;

	w = write(fd, text_content, len);
	if (w == -1 || w != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
