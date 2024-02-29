#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Ptr to the node to insert the right-child in
 * @value: Val to store in the new node
 *
 * Return: Ptr to the created node, or NULL on failure/if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nn;

	if (!parent)
		return (NULL);

	/* Allocate memory for the new node */
	nn = malloc(sizeof(binary_tree_t));
	if (!nn)
		return (NULL);

	nn->n = value;
	nn->parent = parent;
	nn->left = NULL;
	nn->right = NULL;

	/* If parent already has a right child, update */
	if (parent->right)
	{
		nn->right = parent->right;
		parent->right->parent = nn;
	}

	parent->right = nn;

	return (nn);
}
