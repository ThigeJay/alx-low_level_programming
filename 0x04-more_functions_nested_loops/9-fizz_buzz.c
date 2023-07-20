#include "main.h"

#define FIZZ "Fizz"
#define BUZZ "Buzz"
#define FIZZ_BUZZ "FizzBuzz"

void _putchar(char c); /* Function to print a single character */

/**
 * main - prints the numbers from 1 to 100, followed by a new line
 * for multiples of three, prints Fizz
 * and for the multiples of five, prints Buzz
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 15 == 0)
        {
            for (int j = 0; FIZZ_BUZZ[j]; j++)
                _putchar(FIZZ_BUZZ[j]);
        }
        else if (i % 3 == 0)
        {
            for (int j = 0; FIZZ[j]; j++)
                _putchar(FIZZ[j]);
        }
        else if (i % 5 == 0)
        {
            for (int j = 0; BUZZ[j]; j++)
                _putchar(BUZZ[j]);
        }
        else
        {
            int num = i;
            if (num == 0)
                _putchar('0');
            else
            {
                if (num < 0)
                {
                    _putchar('-');
                    num = -num;
                }

                char num_str[12]; /* Maximum length of an integer string */
                int idx = 0;

                while (num != 0)
                {
                    num_str[idx++] = '0' + (num % 10);
                    num /= 10;
                }

                for (int j = idx - 1; j >= 0; j--)
                    _putchar(num_str[j]);
            }
        }

        if (i < 100)
            _putchar(' ');
    }

    _putchar('\n');

    return (0);
}

void _putchar(char c)
{
    putchar(c);
}
