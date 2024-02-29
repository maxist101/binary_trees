#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);

/**
 * find_node - Func finds node with a specific value in a BST
 * @root: Ptr to the root node
 * @value: Value to search for in the tree
 *
 * Return: Ptr to node with the specified value, NULL otherwise
 */
bst_t *find_node(bst_t *root, int value)
{
	if (!root || root->n == value)
		return (root);

	if (value < root->n)
		return (find_node(root->left, value));
	else
		return (find_node(root->right, value));
}

/**
 * find_successor - Func finds the in-order successor of a node
 * @node: Ptr to the node
 *
 * Return: Ptr to the in-order successor
 */
bst_t *find_successor(bst_t *node)
{
	bst_t *successor = node->right;

	while (successor->left != NULL)
		successor = successor->left;

	return (successor);
}

/**
 * remove_node - Func removes a node from a BST
 * @root: Ptr to the root node of the tree
 * @node_to_remove: Ptr to the node to be removed
 *
 * Return: Ptr to the new root node
 */
bst_t *remove_node(bst_t *root, bst_t *node_to_remove)
{
	bst_t *new_n;

	/* Different cases when removing a node */
	if (!node_to_remove->left)
	{
		/* Node has no left child or one child */
		if (node_to_remove->right != NULL)
			node_to_remove->right->parent = node_to_remove->parent;

		if (node_to_remove->parent == NULL)
			root = node_to_remove->right;
		else if (node_to_remove == node_to_remove->parent->left)
			node_to_remove->parent->left = node_to_remove->right;
		else
			node_to_remove->parent->right = node_to_remove->right;

		free(node_to_remove);
	}
	else if (!node_to_remove->right)
	{
		/* Node has no right child */
		node_to_remove->left->parent = node_to_remove->parent;

		if (!node_to_remove->parent)
			root = node_to_remove->left;
		else if (node_to_remove == node_to_remove->parent->left)
			node_to_remove->parent->left = node_to_remove->left;
		else
			node_to_remove->parent->right = node_to_remove->left;

		free(node_to_remove);
	}
	else
	{
		/* Find the in-order successor */
		new_n = find_successor(node_to_remove);

		/* Replace node with its in-order successor */
		if (new_n->right != NULL)
			new_n->right->parent = new_n->parent;

		if (!new_n->parent)
			root = new_n->right;
		else if (new_n == new_n->parent->left)
			new_n->parent->left = new_n->right;
		else
			new_n->parent->right = new_n->right;

		/* Copy value from the in-order successor to the original node */
		node_to_remove->n = new_n->n;

		free(new_n);
	}

	return (root);
}

/**
 * bst_remove - Func removes a node from a BST
 * @root: Ptr to the root node of the tree
 * @value: Value to remove in tree
 *
 * Return: Ptr to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_remove;

	if (!root)
		return (NULL);

	/* Find the node to be removed */
	node_to_remove = find_node(root, value);

	if (!node_to_remove)
		return (root);

	return (remove_node(root, node_to_remove));
}
