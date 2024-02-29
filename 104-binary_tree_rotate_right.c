#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Func performs a right-rotation on a binary tree
 * @tree: Ptr to the root node of the tree to rotate
 *
 * Return: Ptr to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *n_root, *subtree;

	if (!tree || !tree->left)
		return (NULL);

	n_root = tree->left;

	/* Update the right child of the original tree */
	subtree = n_root->right;
	n_root->right = tree;
	tree->left = subtree;

	/* Update parent pointers */
	if (subtree != NULL)
		subtree->parent = tree;

	subtree = tree->parent;
	tree->parent = n_root;
	n_root->parent = subtree;

	/* Update parent's child pointer */
	if (subtree != NULL)
	{
		if (subtree->left == tree)
			subtree->left = n_root;
		else
			subtree->right = n_root;
	}

	return (n_root);
}
