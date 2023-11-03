/*This program prints the alphabet in lowercase letters.*/
#include "main.h"
/**
 *print_square - Entry point
 *
 *Description: This is the main function that prints the alphabet.
 *@size:side of square
 *Return: Always returns 0 for successful execution.
 *
 */
void print_square(int size)
{
int x, y;
if (size <= 0)
{
_putchar('\n');
}
else
{
for (x = 0; x < size; x++)
{
for (y = 0; y < size; y++)
{
_putchar(35);
}
_putchar('\n');
}
}
}
