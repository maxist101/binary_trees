#include "binary_trees.h"

/**
 * binary_tree_is_root - Func checks if a node is a root
 * @node: Ptr to the node to check
 *
 * Return: 1 if node is a root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	/* If the node has no parent(is a root) */
	if (!node->parent)
		return (1);
	return (0);
}
