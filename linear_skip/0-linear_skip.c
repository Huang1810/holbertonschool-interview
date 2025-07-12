#include <stdio.h>
#include "search.h"

/**
 * linear_search - Searches linearly in a skip list segment
 * @start: Pointer to start node
 * @end: Pointer to end node (inclusive)
 * @value: Value to search for
 *
 * Return: Pointer to node where value is found or NULL
 */
skiplist_t *linear_search(skiplist_t *start, skiplist_t *end, int value)
{
	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}
	return (NULL);
}

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to head of skip list
 * @value: Value to search for
 *
 * Return: Pointer to node where value is found or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *express;

	if (!list)
		return (NULL);

	express = list;
	while (express->express && express->express->n < value)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       express->index, express->n);
	}

	prev = express;
	if (express->express)
	{
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       express->index, express->n);
	}
	else
	{
		while (express->next)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, express->index);

	return (linear_search(prev, express, value));
}
