#include "binary_trees.h"

/**
 * binary_tree_depth - Func measures the depth of a node in a binary tree
 * @tree: Ptr to the node to measure the depth
 *
 * Return: Depth of the node, 0 if tree is NULL or has no parent
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
