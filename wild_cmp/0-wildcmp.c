#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if identical, 0 otherwise
 * @s1: first string
 * @s2: second string, can contain the special character '*'
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    if (*s2 == '*')
    {
        while (*(s2 + 1) == '*') /* Skip consecutive '*' */
            s2++;

        if (*(s2 + 1) == '\0')
            return (1);

        if (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)))
            return (1);
    }

    if (*s1 == *s2 && *s1 != '\0')
        return (wildcmp(s1 + 1, s2 + 1));

    return (0);
}
