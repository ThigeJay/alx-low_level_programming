#include "main.h"

int open_files(char *src, char *dest);
void copy_content(int fd_from, int fd_to);
void close_files(int fd_from, int fd_to);

/**
 * main - Entry point. Copy content of one file to another.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_files(argv[1], argv[2]);
	fd_to = open_files(argv[2], NULL);

	copy_content(fd_from, fd_to);
	close_files(fd_from, fd_to);

	return (0);
}
/**
 * open_files - Opens source and destination files.
 * @filename: Name of the file.
 * @text_content: Content to be written.
 * Return: File descriptor on success.
 */

int open_files(char *filename, char *text_content)
{
	int fd;

	if (text_content)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (fd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
			exit(99);
		}
	}
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
			exit(98);
		}
	}
	return (fd);
}

/**
 * copy_content - Copies content from source to destination.
 * @fd_from: File descriptor of the source.
 * @fd_to: File descriptor of the destination.
 */
void copy_content(int fd_from, int fd_to)
{
	int r, w;
	char buf[1024];

	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write\n");
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read\n");
		exit(98);
	}
}

/**
 * close_files - Closes file descriptors.
 * @fd_from: File descriptor of the source.
 * @fd_to: File descriptor of the destination.
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}
