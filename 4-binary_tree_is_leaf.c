#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Func checks if a node is a leaf
 * @node: Ptr to the node to check
 *
 * Return: 0 if node is NULL, 1 if is a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	/* If the node has no left and right children(is a leaf) */
	if (!node->left && !node->right)
		return (1);
	return (0);
}
