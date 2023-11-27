#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 * it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         0 if the file cannot be opened or read, or if filename is NULL.
 *         0 if write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_chars, write_chars;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	read_chars = read(fd, buf, letters);
	if (read_chars == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	write_chars = write(STDOUT_FILENO, buf, read_chars);
	if (write_chars == -1 || write_chars != read_chars)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (read_chars);
}
