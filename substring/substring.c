#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "substring.h"

/**
 * find_substring - finds substring indices containing all words exactly once
 *
 * @s: input string
 * @words: list of words
 * @nb_words: number of words
 * @n: output count of found indices
 *
 * Return: array of starting indices or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int s_len, word_len, total_len;
    int i, j, k;
    int *result = NULL;
    int count = 0;

    *n = 0;
    if (!s || !words || nb_words == 0)
        return (NULL);

    s_len = strlen(s);
    word_len = strlen(words[0]);
    total_len = word_len * nb_words;

    if (s_len < total_len)
        return (NULL);

    /* Allocate word count array */
    int *word_count = calloc(nb_words, sizeof(int));
    if (!word_count)
        return (NULL);

    /* Build word frequency table */
    for (i = 0; i < nb_words; i++)
        word_count[i]++;

    /* Allocate result array (maximum s_len possible matches) */
    result = malloc(sizeof(int) * s_len);
    if (!result)
    {
        free(word_count);
        return (NULL);
    }

    /* MAIN SEARCH */
    for (i = 0; i <= s_len - total_len; i++)
    {
        int *seen = calloc(nb_words, sizeof(int));
        if (!seen)
            break;

        for (j = 0; j < nb_words; j++)
        {
            const char *sub = s + i + j * word_len;

            /* Find which word matches sub */
            for (k = 0; k < nb_words; k++)
            {
                if (!strncmp(sub, words[k], word_len))
                {
                    seen[k]++;
                    break;
                }
            }

            /* No match found */
            if (k == nb_words || seen[k] > word_count[k])
                break;
        }

        /* Valid concatenation */
        if (j == nb_words)
            result[count++] = i;

        free(seen);
    }

    free(word_count);

    /* No matches found */
    if (count == 0)
    {
        free(result);
        return (NULL);
    }

    *n = count;
    return (result);
}
