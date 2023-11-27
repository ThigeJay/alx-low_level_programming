#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file (NULL-terminated string).
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, nletters, rwr;

	/* Check if filename is NULL */
	if (!filename)
		return (-1);

	/* Open file with specific permissions: rw------- */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	/* Check if open operation fails */
	if (fd == -1)
		return (-1);

	/* If text_content is NULL, create an empty file */
	if (!text_content)
		text_content = "";

	/* Calculate the number of letters in text_content */
	for (nletters = 0; text_content[nletters]; nletters++)
		;

	/* Write text_content to the file */
	rwr = write(fd, text_content, nletters);

	/* Check if write operation fails */
	if (rwr == -1)
		return (-1);

	/* Close the file descriptor */
	close(fd);

	return (1);
}
