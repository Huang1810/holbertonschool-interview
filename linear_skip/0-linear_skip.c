#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer on the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end;

	if (!list)
		return (NULL);

	start = list;
	end = list->express;

	/* Traverse express lane first */
	while (end)
	{
		printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
		if (end->n >= value)
			break;

		start = end;
		end = end->express;
	}

	/* If end is NULL, we reached the end of express lane */
	if (!end)
	{
		end = start;
		while (end->next)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", start->index, end->index);

	/* Linear search between start and end (inclusive) */
	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		if (start->n == value)
			return (start);
		if (start->n > value)
			break;
		start = start->next;
	}

	return (NULL);
}
