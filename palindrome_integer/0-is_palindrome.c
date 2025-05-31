#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned integer is a palindrome.
 * @n: The number to be checked.
 * 
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned long original = n;
    unsigned long reversed = 0;
    unsigned long remainder;

    if (n == 0)  /* 0 is a palindrome */
        return 1;

    while (n > 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return (original == reversed) ? 1 : 0;
}