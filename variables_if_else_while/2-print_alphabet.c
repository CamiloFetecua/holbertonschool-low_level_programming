/*This program prints the alphabet in lowercase letters.*/
#include <stdio.h>
/**
*main - Entry point
*
*Description: This is the main function that prints the alphabet.
*Return: Always returns 0 for successful execution.
*
*/
int main(void)
{
char letra;
for (letra = 'a'; letra <= 'z'; letra++)
{
putchar(letra);
}
putchar('\n');
return (0);
}
