#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Function Prototypes for the first 3 tasks */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/* Function Prototypes for cp task */
char *generate_buffer(char *file_name);
void close_descriptor(int file_descriptor);
int main(int arg_count, char *args[]);

/* Function Prototypes for the ELF task */
void validate_elf(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_elf_version(unsigned char *e_ident);
void display_os_interface(unsigned char *e_ident);
void display_elf_abi_version(unsigned char *e_ident);
void display_elf_file_type(unsigned int e_type, unsigned char *e_ident);
void display_entry_point(unsigned long int e_entry, unsigned char *e_ident);

#endif /* MAIN_H */
