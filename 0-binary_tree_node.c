#include "binary_trees.h"

/**
 * binary_tree_node - Func creates a binary tree node
 * @parent: A pointer to the parent node of the node to create
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nn;

	/* Allocate memory for the nn(new node) */
	nn = malloc(sizeof(binary_tree_t));
	if (!nn)
		return (NULL);

	/* Initialize the nn(new node) */
	nn->n = value;
	nn->parent = parent;
	nn->left = NULL;
	nn->right = NULL;

	return (nn);
}
