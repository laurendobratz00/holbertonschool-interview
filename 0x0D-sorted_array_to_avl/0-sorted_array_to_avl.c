#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array
 * @array: int pointer
 * @size: size_t
 * Return: a pointer to the root node of created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int *temp = NULL;

	temp = malloc(sizeof(int) * size);
	if (array == NULL)
	{
		return (NULL);
	}
	selectionSort(temp, size);
	binary_tree_print(temp);
	return (temp);
	free(temp);
}

/**
 * selectionSort - sorting array
 * @arr: array to sort
 * @size: size of array
 * Return: void
 */

void selectionSort(int arr[], size_t size)
{
	int i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		swap(&arr[min_idx], &arr[i]);
	}
}

/**
 * swap - swap function
 * @x: int
 * @y: int
 * Return: void
 */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}
