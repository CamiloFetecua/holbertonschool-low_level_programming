/*This program prints a string without funtion loop:.*/
#include "main.h"
/**
 *_print_rev_recursion - prints a string in reverse
 *@s: pointer block of memory to fill
 *Return: void
 */
void _print_rev_recursion(char *s)
{
if (*s != '\0')
{
_print_rev_recursion(s + 1);
_putchar(*s);
}
}
