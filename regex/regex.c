#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if pattern matches str, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	/* If pattern is empty, string must also be empty */
	if (!*pattern)
		return (!*str);

	/* Check if characters match or if pattern has '.' */
	first_match = (*str && (*str == *pattern || *pattern == '.'));

	/*
	 * If next char is '*', two choices:
	 *   - Skip "x*" (match zero occurrences)
	 *   - Or consume one char from str if matching
	 */
	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}

	/* Otherwise match current char and move on */
	return (first_match && regex_match(str + 1, pattern + 1));
}
