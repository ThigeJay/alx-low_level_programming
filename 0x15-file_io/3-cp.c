#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *generate_buffer(char *file_name);
void close_descriptor(int file_descriptor);

/**
 * generate_buffer - Creates a buffer with 1024 bytes.
 * @file_name: The file associated with the buffer.
 * Return: A pointer to the allocated buffer.
 */
char *generate_buffer(char *file_name)
{
	char *buf;

	buf = malloc(1024 * sizeof(char));

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file_name);
		exit(99);
	}

	return (buf);
}

/**
 * close_descriptor - Closes provided file descriptor.
 * @file_descriptor: The descriptor to be closed.
 */
void close_descriptor(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * main - Duplicates the content from one file to another.
 * @arg_count: Count of arguments given to the program.
 * @args: Array containing the program arguments.
 * Return: 0 if successful.
 */
int main(int arg_count, char *args[])
{
	int src, dest, read_val, write_val;
	char *buf;

	if (arg_count != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file dest_file\n");
		exit(97);
	}

	buf = generate_buffer(args[2]);
	src = open(args[1], O_RDONLY);
	read_val = read(src, buf, 1024);
	dest = open(args[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src == -1 || read_val == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Unable to read from file %s\n", args[1]);
			free(buf);
			exit(98);
		}

		write_val = write(dest, buf, read_val);
		if (dest == -1 || write_val == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Unable to write to %s\n", args[2]);
			free(buf);
			exit(99);
		}

		read_val = read(src, buf, 1024);
		dest = open(args[2], O_WRONLY | O_APPEND);

	} while (read_val > 0);

	free(buf);
	close_descriptor(src);
	close_descriptor(dest);

	return (0);
}
