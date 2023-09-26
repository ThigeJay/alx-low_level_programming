#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void validate_elf_format(unsigned char *ident);
void display_magic(unsigned char *ident);
void display_class(unsigned char *ident);
void display_data(unsigned char *ident);
void display_elf_version(unsigned char *ident);
void display_os_interface(unsigned char *ident);
void display_elf_file_type(unsigned int type, unsigned char *ident);
void display_entry_point(unsigned long int entry, unsigned char *ident);
void finalize_elf(int elf_descriptor);

/**
 * validate_elf_format - Confirms the file as an ELF file.
 * @ident: Pointer to an array with the ELF magic numbers.
 */
void validate_elf_format(unsigned char *ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (ident[idx] != 127 && ident[idx] != 'E' && ident[idx]
		!= 'L' && ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: This is not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * display_magic - Prints the magic numbers from the ELF header.
 * @ident: Pointer to an array with the ELF magic numbers.
 */
void display_magic(unsigned char *ident)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_class - Outputs the class from the ELF header.
 * @ident: Pointer to an array with the ELF class.
 */
void display_class(unsigned char *ident)
{
	printf(" Class: ");

	switch (ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * display_data - Shows the data from the ELF header.
 * @ident: Pointer to an array with the ELF class.
 */
void display_data(unsigned char *ident)
{
	printf(" Data: ");

	switch (ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}
/**
 * display_elf_version - Prints the version from the ELF header.
 * @ident: Pointer to an array containing the ELF version.
 */
void display_elf_version(unsigned char *ident)
{
	printf(" Version: %d",
		ident[EI_VERSION]);

	switch (ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * display_os_interface - Outputs the OS/ABI from the ELF header.
 * @ident: Pointer to an array containing the ELF version.
 */
void display_os_interface(unsigned char *ident)
{
	printf(" OS/ABI: ");

	switch (ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_OSABI]);
	}
}

/**
 * display_elf_file_type - Outputs the type from the ELF header.
 * @type: The ELF file type.
 * @ident: Pointer to an array containing the ELF class.
 */
void display_elf_file_type(unsigned int type, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf(" Type: ");

	switch (type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type);
	}
}

/**
 * display_entry_point - Shows the entry point address from the ELF header.
 * @entry: Address of the ELF entry point.
 * @ident: Pointer to an array containing the ELF class.
 */
void display_entry_point(unsigned long int entry, unsigned char *ident)
{
	printf(" Entry point address: ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}
/**
 * finalize_elf - Closes an ELF file.
 * @elf_descriptor: The file descriptor of the ELF file.
 */
void finalize_elf(int elf_descriptor)
{
	if (close(elf_descriptor) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Couldn't close fd %d\n", elf_descriptor);
		exit(98);
	}
}
/**
 * main - Displays info from the ELF header at the start of an ELF file.
 * @argc: Number of arguments supplied to the program.
 * @argv: Array of pointers to the supplied arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *hdr;
	int file_descriptor;
	ssize_t status;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	hdr = malloc(sizeof(Elf64_Ehdr));
	if (!hdr)
	{
		dprintf(STDERR_FILENO, "Memory error\n");
		close(file_descriptor);
		exit(98);
	}

	status = read(file_descriptor, hdr, sizeof(Elf64_Ehdr));
	if (status == -1)
	{
		free(hdr);
		close(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	validate_elf(hdr->e_ident);
	printf("ELF Header:\n");
	display_magic(hdr->e_ident);
	display_class(hdr->e_ident);
	display_data(hdr->e_ident);
	display_elf_version(hdr->e_ident);
	display_os_interface(hdr->e_ident);
	display_elf_abi_version(hdr->e_ident);
	display_elf_file_type(hdr->e_type, hdr->e_ident);
	display_entry_point(hdr->e_entry, hdr->e_ident);

	free(hdr);
	close_elf(file_descriptor);
	return (0);
}
