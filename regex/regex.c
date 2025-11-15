#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if pattern matches str, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
    /* If pattern is empty, string must also be empty */
    if (!*pattern)
        return (!*str);

    /* Check if current characters match or if pattern has '.' */
    int first_match = (*str && (*str == *pattern || *pattern == '.'));

    /*
     * If next character in pattern is '*', then we have two choices:
     *   - Treat the '*' as matching zero occurrences of preceding char
     *   - Treat the '*' as matching one occurrence (if first_match is true)
     */
    if (*(pattern + 1) == '*')
    {
        return (regex_match(str, pattern + 2) ||       /* zero occurrences */
               (first_match && regex_match(str + 1, pattern))); /* one+ occurrences */
    }

    /* Otherwise match current char and move to next */
    return (first_match && regex_match(str + 1, pattern + 1));
}
