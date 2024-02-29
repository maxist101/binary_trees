#include "binary_trees.h"

/**
 * binary_tree_leaves - Func counts the leaves in a binary tree
 * @tree: Ptr to the root node of the tree to count the leaves
 *
 * Return: Num of leaves in the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Check if the current node is a leaf */
	if (!tree->left)
		return (1);

	if (!tree->right)
		return (1);

	/* Count leaves in left and right subtrees */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
