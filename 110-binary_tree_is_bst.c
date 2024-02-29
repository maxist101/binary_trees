#include "binary_trees.h"

/**
 * is_valid - Func checks if a binary tree is a valid BST
 * @tree: Ptr to the root node of the tree
 * @low: Lowest valid value
 * @top: Top valid value
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_valid(const binary_tree_t *tree, int low, int top)
{
	if (!tree)
		return (1);

	if (tree->n <= low || tree->n >= top)
		return (0);

	return (is_valid(tree->left, low, tree->n) &&
			is_valid(tree->right, tree->n, top));
}

/**
 * binary_tree_is_bst - Func checks if a binary tree is a valid BST
 * @tree: Ptr to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_valid(tree, INT_MIN, INT_MAX));
}
