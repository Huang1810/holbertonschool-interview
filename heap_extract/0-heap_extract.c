#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Maintains the max-heap property after extraction.
 * @node: The node to heapify down from.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest;
    int temp;

    if (!node)
        return;

    while (node)
    {
        largest = node;
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;

        if (largest == node)
            break;

        temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        node = largest;
    }
}

/**
 * get_last_node - Gets the last node (rightmost, deepest node) in level order.
 * @root: Pointer to the root of the heap.
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t **queue, *last = NULL;
    size_t front = 0, rear = 0, size = 1024;

    if (!root)
        return (NULL);

    queue = malloc(sizeof(heap_t *) * size);
    if (!queue)
        return (NULL);

    queue[rear++] = root;

    while (front < rear)
    {
        last = queue[front++];
        if (last->left)
            queue[rear++] = last->left;
        if (last->right)
            queue[rear++] = last->right;
    }

    free(queue);
    return (last);
}

/**
 * heap_extract - Extracts the root value from a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The extracted value, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *parent;
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    last = get_last_node(*root);
    if (!last)
        return (0);

    (*root)->n = last->n;

    parent = last->parent;
    if (parent->right == last)
        parent->right = NULL;
    else
        parent->left = NULL;

    free(last);
    heapify_down(*root);

    return (value);
}
