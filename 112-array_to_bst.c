#include "binary_trees.h"

/**
 * array_to_bst - Func builds a BST from an array
 * @array: Ptr to the first element of the array
 * @size: Num of element in the array
 *
 * Return: Ptr to the root node,NULL otherwise
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t u = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);

	/* Iteration and insert each element into the BST */
	while (u < size)
	{
		bst_insert(&root, array[u]);
		u++;
	}

	return (root);
}
