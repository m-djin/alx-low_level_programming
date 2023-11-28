#include "main.h"
#include <elf.h>

void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_Magic(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_ABI(unsigned char *e_ident);
void print_OS_ABI(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void end_elf(int elf);

/**
 * main - displays the information contained
 * in the ELF header at the start of an ELF file
 * @argc: number of arguments
 * @argv: arguments passed
 * Return: 0
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int i, j;

	i = open(argv[1], O_RDONLY);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file%s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		end_elf(i);
		dprintf(STDERR_FILENO, "Error: Can't read file%s\n", argv[1]);
		exit(98);
	}

	j = read(i, header, sizeof(Elf64_Ehdr));
	if (j == -1)
	{
		free(header);
		end_elf(i);
		dprintf(STDERR_FILENO, "Error: '%s' : No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_Magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_OS_ABI(header->e_ident);
	print_ABI(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	end_elf(i);
	return (0);
}

/**
 * check_elf - checks if file is ELF file
 * @e_ident: point to array
 */

void check_elf(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 &&
				e_ident[ind] != 'E' &&
				e_ident[ind] != 'L' &&
				e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_Magic - prints magic number
 * @e_ident: pointer to an array
 * Desription: magic number seperated by spaces
 */

void print_Magic(unsigned char *e_ident)
{
	int ind;

	printf("  Magic:   ");
	for (ind = 0 ; ind < EI_NIDENT ; ind++)
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class
 * @e_ident: points to an array
 */

void print_class(unsigned char *e_ident)
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
 * print_data - ptrints the data
 * @e_ident: poitner to array
 */

void print_data(unsigned char *e_ident)
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
 * print_version - prints the version
 * @e_ident: poitns to anarray
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident
			[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_OS_ABI - prints OS/ABI
 * @e_ident: pointer to array
 */

void print_OS_ABI(unsigned char *e_ident)
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
		printf("UNIX - NETBSD\n");
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
		printf("standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_ABI - prints ABI
 * @e_ident: pointer to array
 */

void print_ABI(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints type
 * @e_type: elf type
 * @e_ident: points to array
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

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
		printf("EXEC (Executable file\n");
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
 * print_entry - prints entry
 * @e_entry:entry point
 * @e_ident: pointer to array
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			 ((e_entry >> 8) & 0xFF00FF);
		e_entry = ((e_entry << 16) | (e_entry >> 16));
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
	printf("%#lx\n", e_entry);
}

/**
 * end_elf - closes the file
 * @elf: file desciptor
 */

void end_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO
				, "Error: Can't close file %d\n", elf);
		exit(98);
	}
}
