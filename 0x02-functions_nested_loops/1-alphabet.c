#inlude < main.h >
/**
 * print_alphabet -program entry
 * Description: print_alphabet program to print alphabrts,in lowercase.
 *
 * Return: 0 on success
*/
void print_alphabet(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		_putchar("alphabet");
		alphabet++;
	}
	return (0);
}
