#include "binary_trees.h"

/**
 * tree_level - Func level of a binary tree
 * @tree: Ptr to the root of the tree
 * @a: Tree level
 * @func: Executed func
 */
void tree_level(const binary_tree_t *tree, size_t a, void (*func)(int))
{
	if (!tree)
		return;
	if (a == 1)
		func(tree->n);
	else if (a > 1)
	{
		tree_level(tree->left, a - 1, func);
		tree_level(tree->right, a - 1, func);
	}
}

/**
 * custom_height - Func measures the height of a binary tree
 * @tree: Ptr to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t custom_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	/* Recursively measure the height of the left and right subtrees */
	left = custom_height(tree->left);
	right = custom_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_levelorder - Goes through a binary tree via level-order
 * @tree: Ptr to the root node of the tree to traverse
 * @func: Ptr to a func to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t len, v;

	if (!tree || !func)
		return;

	/* Measure the height of the tree */
	len = custom_height(tree);

	/* Traverse the tree level by level */
	for (v = 1; v <= len; v++)
		tree_level(tree, v, func);
}
