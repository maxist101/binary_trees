#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree via post-order traversal
 * @tree: Ptr to the root node of the tree to traverse
 * @func: Ptr to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	if (!func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
