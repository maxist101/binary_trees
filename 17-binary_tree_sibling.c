#include "binary_trees.h"

/**
 * binary_tree_sibling - Func finds the sibling of a node
 *
 * @node: Ptr to the node to find the sibling
 *
 * Return: Ptr to the sibling node, or NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->right == node)
		return (node->parent->left);

	return (node->parent->right);
}
