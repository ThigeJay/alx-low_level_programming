#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Function Prototypes for first 3 tasks*/
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/* Function Prototypes for cp task */
char *generate_buffer(char *file_name);
void close_descriptor(int file_descriptor);
int main(int arg_count, char *args[]);

#endif /* MAIN_H */
