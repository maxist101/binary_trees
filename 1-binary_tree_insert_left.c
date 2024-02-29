#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node,or NULL on failure/if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nn;

	if (!parent)
		return (NULL);

	/* Allocate memory for the nn(new node) */
	nn = malloc(sizeof(binary_tree_t));
	if (!nn)
		return (NULL);

	nn->n = value;
	nn->parent = parent;
	nn->left = NULL;
	nn->right = NULL;

	/* If parent already has a left child, update */
	if (parent->left)
	{
		nn->left = parent->left;
		parent->left->parent = nn;
	}

	parent->left = nn;

	return (nn);
}
