#include "binary_trees.h"

/**
 * bst_search - Func searches for a value in a BST
 * @tree: Ptr to the root node of th BST
 * @value: Value to search in the tree
 *
 * Return: Ptr to the node containing a value,NULL otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return ((bst_t *)tree);

	/* if value is less/greater than current node's,search in subtrees */
	if (value < tree->n)
		return (bst_search(tree->left, value));

	return (bst_search(tree->right, value));
}
