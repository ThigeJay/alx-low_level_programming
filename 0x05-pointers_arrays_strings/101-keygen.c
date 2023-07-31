#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program
 * 101-crackme.
 *
 * Return: 0 on success
 */

int main(void)
{
    int sum = 0;
    char a;
    srand(time(NULL));

    while (sum < 2772 - 126 - 32)
    {
        a = rand() % (126 - 32 + 1) + 32;
        sum += a;
        putchar(a);
    }

    putchar(2772 - sum);

    return (0);
}

