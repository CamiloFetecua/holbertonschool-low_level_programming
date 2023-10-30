#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Zero, positive,negative*/
/*
 *main - Entry point
 *This is the main function that assigns a random number to the variable 'n'
 *and prints whether the number is positive, negative, or zero.
 *
 *Return: Always 0 (Success)
*/
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
if (n == 0)
{
printf("%d is zero\n", n);
}
else if (n < 0)
{
printf("%d is negative\n", n);
}
else
{
printf("%d is positive\n", n);
}
return (0);
}
