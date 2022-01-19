#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s avl_t;

avl_t *sorted_array_to_avl(int *array, size_t size);
/* static int print_t(const binary_tree_t *tree, int offset, int depth, char **s);
static size_t _height(const binary_tree_t *tree); */
void binary_tree_print(const binary_tree_t *tree);
void selectionSort(int arr[], size_t size);
void swap(int *x, int *y);

#endif
