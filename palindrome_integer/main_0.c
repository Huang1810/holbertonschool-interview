#include <stdio.h>
#include "palindrome.h"

int main(void)
{
    unsigned long n = 12321;

    if (is_palindrome(n))
        printf("%lu is a palindrome\n", n);
    else
        printf("%lu is not a palindrome\n", n);

    return 0;
}
