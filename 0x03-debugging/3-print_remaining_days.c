#include <stdio.h>
#include "main.h"
/**
 * print_remaining_days - program picks a random date and prints
 * how many days are left in the year,leap years considered
 * @day: day of month
 * @month: month of the year
 * @year: year....
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0))
{
if (month > 2 && day >= 60)
{
day++;
}
printf("Day: %d\n", day);
printf("Remaining days: %d\n", 366 - day);
}
else
{
if (month == 2 && day == 60)
{
printf("Date N/A: %02d/%02d/%04d\n", month, day - 31, year);
}
else
{
printf("Day: %d\n", day);
printf("Remaining days: %d\n", 365 - day);
}
}
}
