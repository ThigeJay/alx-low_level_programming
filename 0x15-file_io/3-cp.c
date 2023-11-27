#include "main.h"
#include <stdio.h>

/**
 * error_file - Checks if files can be opened and
 * exits with appropriate error code.
 * @file_from: File descriptor of the source file.
 * @file_to: File descriptor of the destination file.
 * @argv: Arguments vector.
 *
 * This function checks if the file_from or file_to file descriptors are -1
 * and prints the corresponding error message
 * before exiting with the appropriate
 * error code.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, close_result;
	ssize_t num_chars, num_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	source_fd = open(argv[1], O_RDONLY);
	destination_fd = open(argv[2], O_CREAT |
	O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(source_fd, destination_fd, argv);

	num_chars = 1024;
	while (num_chars == 1024)
	{
		num_chars = read(source_fd, buffer, 1024);
		if (num_chars == -1)
			error_file(-1, 0, argv);
		num_written = write(destination_fd, buffer, num_chars);
		if (num_written == -1)
			error_file(0, -1, argv);
	}

	close_result = close(source_fd);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}

	close_result = close(destination_fd);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destination_fd);
		exit(100);
	}
	return (0);
}
