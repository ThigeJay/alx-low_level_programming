#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define ELF_MAGIC_SIZE 4
/*
 * struct ElfHeader - ELF Header structure
 * @e_ident: ELF identification
 * @e_type: Type of file (e.g., relocatable, executable)
 * @e_machine: Target architecture (e.g., x86_64)
 * @e_version: ELF format version
 * @e_entry: Entry point virtual address
 * @e_phoff: Program header table offset
 * @e_shoff: Section header table offset
 * @e_flags: Processor-specific flags
 * @e_ehsize: ELF header size
 * @e_phentsize: Size of a program header table entry
 * @e_phnum: Number of entries in the program header table
 * @e_shentsize: Size of a section header table entry
 * @e_shnum: Number of entries in the section header table
 * @e_shstrndx: Section header table index of the entry
 * associated with the section name string table
 */
struct ElfHeader
{
	unsigned char e_ident[EI_NIDENT];
	Elf64_Half e_type;
	Elf64_Half e_machine;
	Elf64_Word e_version;
	Elf64_Addr e_entry;
	Elf64_Off e_phoff;
	Elf64_Off e_shoff;
	Elf64_Word e_flags;
	Elf64_Half e_ehsize;
	Elf64_Half e_phentsize;
	Elf64_Half e_phnum;
	Elf64_Half e_shentsize;
	Elf64_Half e_shnum;
	Elf64_Half e_shstrndx;
};

void handle_error(const char *message);
void check_elf(const unsigned char *e_ident);
void read_elf_header(int fd, ElfHeader *header);
void print_magic(const unsigned char *e_ident);
void print_class(const unsigned char *e_ident);
void print_data(const unsigned char *e_ident);
void print_version(const unsigned char *e_ident);
void print_osabi(const unsigned char *e_ident);
void print_abi(const unsigned char *e_ident);
void print_type(Elf64_Half e_type, const unsigned char *e_ident);
void print_entry(Elf64_Addr e_entry, const unsigned char *e_ident);
void close_elf(int fd);
/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Description: Opens an ELF file, reads its header,
 * and prints relevant information.
 * Exits with an error message if the file cannot be opened.
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fd;
	ElfHeader header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		handle_error("Can't open file");
	}

	read_elf_header(fd, &header);

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close_elf(fd);
	return (0);
}
/**
 * handle_error - Handles errors by printing an
 * error message and exiting.
 * @message: The error message to be printed.
 *
 * Description: Prints the error message using perror
 * and exits with code 98.
 */

void handle_error(const char *message)
{
	perror(message);
	exit(98);
}
/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exits with code 98.
 */

void check_elf(const unsigned char *e_ident)
{
	int i;
	for (i = 0; i < ELF_MAGIC_SIZE; i++)
	{
		if (e_ident[i] != ELFMAG[i])
		{
			handle_error("Not an ELF file");
		}
	}
}

/**
 * read_elf_header - Reads the ELF header from a file descriptor.
 * @fd: File descriptor of the ELF file.
 * @header: Pointer to ElfHeader structure to store header information.
 *
 * Description: Reads the ELF header from the file descriptor and
 * checks if it's a valid ELF file.
 * Exits with an error message if reading fails
 * or if it's not an ELF file.
 */

void read_elf_header(int fd, ElfHeader *header)
{
	ssize_t n = read(fd, header, sizeof(ElfHeader));
	if (n == -1)
	{
		handle_error("Error reading ELF header");
	}

	check_elf(header->e_ident);
}

/**
 * print_magic - Prints the ELF magic numbers.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the magic numbers in hexadecimal format.
 */

void print_magic(const unsigned char *e_ident)
{
	int i;
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * print_class - Prints the ELF class information.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF class (32-bit or 64-bit)
 * based on the provided information.
 */

void print_class(const unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - Prints the ELF data encoding information.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF dataencoding (little-endian
 * or big-endian) based on the provided information.
 */

void print_data(const unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_version - Prints the ELF version information.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF version
 * information based on the provided information.
 */

void print_version(const unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
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
 * print_osabi - Prints the ELF OS/ABI information.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF OS/ABI
 * information based on the provided information.
 */

void print_osabi(const unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - Prints the ELF ABI version information.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF ABI version
 * information based on the provided information.
 */

void print_abi(const unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * print_type - Prints the ELF type information.
 * @e_type: ELF type.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF type (e.g.,
 * executable, shared object) based on the provided information.
 */

void print_type(Elf64_Half e_type, const unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}

	printf("  Type:                              ");
	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - Prints the ELF entry point address.
 * @e_entry: ELF entry point address.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Prints the ELF entry point address
 * based on the provided information.
 */

void print_entry(Elf64_Addr e_entry, const unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
	else
	{
		printf("%#lx\n", e_entry);
	}
}
/**
 * close_elf - Closes the file descriptor for the ELF file.
 * @fd: File descriptor of the ELF file.
 *
 * Description: Closes the file descriptor and exits with
 * an error message if closing fails.
 */

void close_elf(int fd)
{
	if (close(fd) == -1)
	{
		handle_error("Can't close file descriptor");
	}
}
