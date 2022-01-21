#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: double pointer to root node of the Heap
 * @value: value stored in node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *x;

	if (*root == NULL || root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	x = insert(*root, value, 0, tree_size(*root) + 1);
	while (x->parent && x->n > x->parent->n)
	{
		x->n = x->parent->n;
		x->parent->n = value;
		x = x->parent;
	}
	return (x);
}

/**
 * tree_size - function to find size of the tree
 * @tree: tree
 * Return: size of tree
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t size = 0, right = 0, left = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left = tree_size(tree->left);
		right = tree_size(tree->right);
		size = right + left + 1;
	}
	return (size);
}

/**
 * insert - inserts node
 * @tree: tree
 * @value: int
 * @index: int
 * @leaf: int
 * Return: node inserted
 */

heap_t *insert(binary_tree_t *tree, int value, int index, int leaf)
{
	heap_t *x;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (index + 1 == leaf / 2)
	{
		if (leaf & 1)
		{
			tree->right = binary_tree_node(tree, value);
			return (tree->right);
		}
		else
		{
			tree->left = binary_tree_node(tree, value);
			return (tree->left);
		}
	}
	x = insert(tree->left, value, 2 * index + 1, leaf);
	if (x != 0)
	{
		return (x);
	}
	else
	{
		return (insert(tree->right, value, 2 * index + 2, leaf));
	}
}
