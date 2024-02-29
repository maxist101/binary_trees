#include "binary_trees.h"

/**
 * binary_tree_uncle - Func finds the uncle of a node
 *
 * @node: Ptr to the node to find the uncle
 *
 * Return: Ptr to the uncle node,or NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	/* If node parent is the left/right child of its grandparent */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	return (NULL);
}
