/*This program prints print n elements of int.*/
#include "main.h"
#include <stdio.h>
/**
 *print_array - Entry point
 *
 *Description: This is the main function print n elements of int.
 *@a: pointer to int
 *@n: int value
 *Return: Always returns 0 for successful execution.
 *
 */
void print_array(int *a, int n)
{
int i;
for (i = 0; i < n; i++)
{
printf("%d", a[i]);
if (i != (n - 1))
{
printf(", ");
}
}
printf("\n");
}
