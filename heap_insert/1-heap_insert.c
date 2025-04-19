#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_up - Maintains the max-heap property by bubbling up
 * @node: Pointer to the node to heapify
 * Return: Pointer to the final position of the node
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
    return node;
}

/**
 * get_size - Measures the size of a binary tree
 * @root: Pointer to the root node
 * Return: Number of nodes
 */
size_t get_size(const heap_t *root)
{
    if (!root)
        return 0;
    return 1 + get_size(root->left) + get_size(root->right);
}

/**
 * get_node_at_index - Gets the node at a given index (level-order)
 * @root: Pointer to the root node
 * @index: Index of the node to find
 * Return: Pointer to the node, or NULL if not found
 */
heap_t *get_node_at_index(heap_t *root, size_t index)
{
    if (!root || index == 0)
        return (heap_t *)root;

    size_t count = 0;
    heap_t **queue = malloc(sizeof(heap_t *) * 1024);
    heap_t *node = NULL;
    if (!queue)
        return NULL;

    queue[count++] = (heap_t *)root;
    size_t i = 0;
    while (i < count)
    {
        node = queue[i];
        if (i == index)
            break;
        if (node->left)
            queue[count++] = node->left;
        if (node->right)
            queue[count++] = node->right;
        i++;
    }
    heap_t *result = (i == index) ? node : NULL;
    free(queue);
    return result;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t size;

    if (!root)
        return NULL;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (!*root)
    {
        *root = new_node;
        return new_node;
    }

    size = get_size(*root);
    parent = get_node_at_index(*root, (size - 1) / 2);
    if (!parent)
    {
        free(new_node);
        return NULL;
    }

    new_node->parent = parent;
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    return heapify_up(new_node);
}
