#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks whether or not an unsigned integer is a palindrome
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    int remainder, original, reversed = 0;

    original = n;
    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
    {
        return (1);
        printf("%d is a palindrome.", original);
    }
    else
    {
        return (0);
        printf("%d is not a palindrome.", original);
    }

    return 0;
}