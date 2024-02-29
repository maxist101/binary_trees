#include "binary_trees.h"

/**
 * bst_insert - Func inserts a value in a Binary Search Tree
 * @tree: Double ptr to the root node of the BST
 * @value: Value to store in the node to be inserted
 *
 * Return: Ptr to the created node, otherwise NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_n = NULL, *current_n = NULL, *parent_n = NULL;

	if (!tree)
		return (NULL);

	current_n = *tree;

	/* Traverse the tree to find the insertion point */
	while (current_n != NULL)
	{
		parent_n = current_n;
		if (current_n->n > value)
			current_n = current_n->left;
		else if (current_n->n < value)
			current_n = current_n->right;
		else
			return (NULL);
	}

	/* Insert new node */
	new_n = binary_tree_node(parent_n, value);
	if (!new_n)
		return (NULL);

	if (!parent_n)
		*tree = new_n;
	else if (value < parent_n->n)
		parent_n->left = new_n;
	else
		parent_n->right = new_n;

	return (new_n);
}
