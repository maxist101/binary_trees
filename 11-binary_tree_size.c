#include "binary_trees.h"

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
