#include "main.h"

/**
 * read_textfile - Reads a text file and prints a
 * specified number of characters.
 * @filename: The name of the file to read.
 * @num_chars: The number of characters to read and print.
 *
 * Return: The actual number of characters read and printed.
 * Returns 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t num_chars)
{
	int file_descriptor;
	ssize_t num_read, num_written;
	char *buffer;

	/* Check if filename is NULL */
	if (!filename)
		return (0);

	/* Open the file for reading */
	file_descriptor = open(filename, O_RDONLY);

	/* Check if open operation fails */
	if (file_descriptor == -1)
		return (0);

	/* Allocate memory for the buffer */
	buffer = malloc(sizeof(char) * num_chars);

	/* Check if memory allocation fails */
	if (!buffer)
		return (0);

	/* Read characters from the file into the buffer */
	num_read = read(file_descriptor, buffer, num_chars);

	/* Write the content of the buffer to standard output */
	num_written = write(STDOUT_FILENO, buffer, num_read);

	/* Close the file descriptor and free the allocated memory */
	close(file_descriptor);
	free(buffer);

	/* Return the actual number of characters read and printed */
	return (num_written);
}
