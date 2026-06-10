#include "binary_trees.h"

/**
 * build_avl - Builds an AVL tree from a sorted array
 * @array: Array of integers
 * @start: Starting index
 * @end: Ending index
 * @parent: Parent node
 *
 * Return: Pointer to root node
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
    int mid;
    avl_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    root = binary_tree_node(parent, array[mid]);
    if (!root)
        return (NULL);

    root->left = build_avl(array, start, mid - 1, root);
    root->right = build_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl(array, 0, (int)size - 1, NULL));
}
