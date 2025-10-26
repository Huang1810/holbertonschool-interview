#include "binary_trees.h"
#include <limits.h>

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * is_avl_helper - helper function to check if a tree is AVL
 * @tree: pointer to the root node of the tree
 * @min: minimum value allowed in this subtree
 * @max: maximum value allowed in this subtree
 * Return: 1 if the tree is AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_h, right_h, diff;

	if (tree == NULL)
		return (1);

	/* Check BST property */
	if (tree->n < min || tree->n > max)
		return (0);

	/* Recursively check left and right subtrees */
	if (!is_avl_helper(tree->left, min, tree->n - 1) ||
	    !is_avl_helper(tree->right, tree->n + 1, max))
		return (0);

	/* Check height balance */
	left_h = height(tree->left);
	right_h = height(tree->right);
	diff = left_h - right_h;

	if (diff < -1 || diff > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
