/*This program prints in reverse a string.*/
#include "main.h"
/**
 *print_rev - Entry point
 *
 *Description: This is the main function that print in reverse a string.
 *@S: text to print
 *Return: Always returns 0 for successful execution.
 *
 */
void print_rev(char *s)
{
int len = 0;
while (*s != 0)
{
s++;
len++;
}
while (len > 0)
{
_putchar(*s);
len--;
s--;
}
_putchar('\n');
}
