#include "binary_trees.h"
#include <stdlib.h>

/* Helper to swap values of two nodes */
void swap_values(heap_t *a, heap_t *b)
{
    int tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/* Helper to find the last node in level-order */
heap_t *last_node(heap_t *root)
{
    size_t count = 0, i;
    heap_t **queue, *node;

    if (!root)
        return NULL;

    /* Count nodes */
    queue = malloc(sizeof(heap_t *) * 1024);
    if (!queue)
        return NULL;

    queue[0] = root;
    for (i = 0; i <= count; i++)
    {
        node = queue[i];
        if (node->left)
            queue[++count] = node->left;
        if (node->right)
            queue[++count] = node->right;
    }

    node = queue[count];
    free(queue);
    return node;
}

/* Heapify down to restore max heap */
void heapify(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;
    if (largest != root)
    {
        swap_values(root, largest);
        heapify(largest);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in root node, 0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *tmp;
    int value;

    if (!root || !*root)
        return 0;

    value = (*root)->n;
    last = last_node(*root);

    if (last == *root)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    (*root)->n = last->n;

    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    free(last);

    heapify(*root);

    return value;
}
