#include "binary_trees.h"

/**
 * recursive_check - Recursively checks if a binary tree is complete
 * @tree: Ptr to the current node
 * @index: Index of the current node
 * @size: Total num of nodes
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int recursive_check(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	/* Recursively check the left and right subtrees */
	return (recursive_check(tree->left, 2 * index + 1, size) &&
			recursive_check(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Func measures the size of a binary tree
 * @tree: Ptr to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* current node + size of left/right subtree */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Func checks if a binary tree is complete
 * @tree: Ptr to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursive_check(tree, 0, binary_tree_size(tree)));
}
