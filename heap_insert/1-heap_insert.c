#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);

	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	size = binary_tree_size(*root);
	parent = get_node_at_index(*root, (size - 1) / 2);

	new_node->parent = parent;
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);
	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_at_index - Gets the node at a given index (level-order)
 * @root: Pointer to the root node
 * @index: Index of the node to retrieve
 *
 * Return: Pointer to the node at the index, or NULL if not found
 */
heap_t *get_node_at_index(heap_t *root, size_t index)
{
	heap_t *queue[1024];
	size_t front = 0, rear = 0, count = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;
	count++;

	size_t i = 0;

	while (i < count)
	{
		heap_t *current = queue[i];

		if (i == index)
			return (current);

		if (current->left)
			queue[count++] = current->left;
		if (current->right)
			queue[count++] = current->right;

		i++;
	}

	return (NULL);
}

/**
 * heapify_up - Maintains the heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		node = node->parent;
	}
}
