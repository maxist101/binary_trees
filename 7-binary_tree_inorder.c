#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree via in-order traversal
 * @tree: Ptr to the root node of the tree to traverse
 * @func: Ptr to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	if (!func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
