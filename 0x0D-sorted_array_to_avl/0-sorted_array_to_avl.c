#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array
 * @array: int pointer
 * @size: size_t
 * Return: a pointer to the root node of created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	/* array = malloc(sizeof(avl_t)); */
	if (array == NULL || size == 0)
	{
		return (NULL);
	}
		/*
		* avl_tree = memcpy (avl_tree, array, size);
		* selectionSort(avl_tree, size);
		* binary_tree_print(avl_tree);
		* return (parent);
		*/
	return (create(array, 0, size - 1, NULL));
	free(array);
}

/**
 * create - create a tree
 * @array: array
 * @l: first node
 * @r: last node
 * @root: root node
 * Return: root node
 */
avl_t *create(int *array, int l, int r, avl_t *root)
{
	int middle;

	if (l > r)
	{
		return (NULL);
	}
	middle = (l + r) / 2;
	root = insert(root, array[middle]);
	if (root == NULL)
	{
		return (NULL);
	}
	root->left = create(array, l, middle - 1, root);
	root->right = create(array, middle + 1, r, root);
	return (root);
}

/**
 * insert - insert node
 * @root: root node
 * @total: all inserted nodes
 * Return: temp
 */
avl_t *insert(avl_t *root, int total)
{
	avl_t *temp = NULL;

	temp = malloc(sizeof(avl_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	(temp)->n = total;
	(temp)->left = NULL;
	(temp)->right = NULL;

	if (root == NULL)
	{
		temp->parent = NULL;
		root = temp;
	}
	else
		temp->parent = root;
	return (temp);
}
