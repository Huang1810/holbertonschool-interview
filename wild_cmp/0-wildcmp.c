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
    /* If both strings end at the same time */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If s2 has a '*', it can match any sequence (including empty) */
    if (*s2 == '*')
    {
        /* Skip consecutive '*' */
        while (*(s2 + 1) == '*')
            s2++;

        /* If *s2 is last char in s2, it matches everything */
        if (*(s2 + 1) == '\0')
            return (1);

        /* Try two recursive paths:
         * 1. Skip the '*' and move to next char in s2
         * 2. Keep '*' in s2 and move to next char in s1
         */
        if (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)))
            return (1);
    }

    /* If characters match, continue recursively */
    if (*s1 == *s2 && *s1 != '\0')
        return (wildcmp(s1 + 1, s2 + 1));

    /* Otherwise, not identical */
    return (0);
}
