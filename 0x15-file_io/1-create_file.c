#include "main.h"
#include <stdlib.h>

/**
 * create_file - creates a file.
 * @filename: name of the file to be created.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600); 
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
