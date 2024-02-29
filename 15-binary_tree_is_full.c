#include "binary_trees.h"

/**
 * binary_tree_is_full - Func checks if a binary tree is full
 * @tree: Ptr to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* If the tree has no child, it is full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If the tree has both children,check recursively for both subtrees */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
