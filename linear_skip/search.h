#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer stored at the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* Function Prototypes */

/**
 * create_skiplist - Creates a skip list from an array
 * @array: Pointer to array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the head of the new skip list
 */
skiplist_t *create_skiplist(int *array, size_t size);

/**
 * free_skiplist - Frees the memory used by a skip list
 * @list: Pointer to the head of the skip list
 */
void free_skiplist(skiplist_t *list);

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_H */
