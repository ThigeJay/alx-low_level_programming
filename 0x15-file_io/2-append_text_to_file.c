#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to be appended.
 *
 * Return: 1 on success, -1 on failure (file does not exist or write fails).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int num_letters;
	int write_result;

	/* Check if the filename is NULL */
	if (!filename)
		return (-1);

	/* Open the file in write-only mode, appending to the end */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	/* Check if the file opening was successful */
	if (file_descriptor == -1)
		return (-1);

	/* Check if text_content is not NULL */
	if (text_content)
	{
		/* Count the number of letters in text_content */
		for (num_letters = 0; text_content[num_letters]; num_letters++)
			;

		/* Write the text_content to the file */
		write_result = write(file_descriptor, text_content, num_letters);

		/* Check if the write operation was successful */
		if (write_result == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	/* Close the file descriptor */
	close(file_descriptor);

	/* Return 1 indicating success */
	return (1);
}
