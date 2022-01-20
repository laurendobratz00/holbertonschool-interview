#include "binary_trees.h"

/**
 * heap_extract - a function that extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of the heap
 * Return: the value stored in the root node, or if function fails, return 0
 */
int heap_extract(heap_t **root)
{
	int *array = NULL, i, n = 0;
	int size = sizeof(array) / sizeof(array[0]);

	if (!root || !*root)
	{
		return (0);
	}
	else if (size == 1)
	{
		binary_tree_print(*root);
	}
	
	else
	{
		for (i = 0; i < size; i++)
		{
			if (n == array[i])
			{
				break;
			}
		}
		swap(&array[i], &array[size - 1]);
		size -= 1;
		for (i = size / 2 - 1; i >= 0; i--)
		{
			max_heapify(array, size, n);
		}
	}
	binary_tree_print(*root);
	return (array[0]);
}
/*{
	int x = 0, i = 0;
	heap_t *temp;
	int array[] = {
		79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
		20, 22, 98, 1, 62, 95
		};
	int max_item = array[0];

	if (!root || !*root)
	{
		return (0);
	}
	temp = (*root);
	max_item = temp->n;
	*root = temp->left;
	*root = root[x - 1];
	x = x - 1;
	free(temp);
	if (*root)
	{
		max_heapify(array, i, x);
	}
	return (max_item);
}*/

/**
 * max_heapify - trickle down
 * @array: array
 * @i: iterater
 * @x: index
 * Return: void
 */
void max_heapify(int array[], int i, int x)
{
	int left = left_child(i), right = right_child(i);
	int largest = i;


	if (left <= x && left > array[largest])
	{
		largest = left;
	}

	if (right <= x && right > largest)
	{
		largest = right;
	}

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		max_heapify(array, largest, x);
	}
}
/**
 * left_child - left
 * @i: i
 * Return: int
 */
int left_child(int i)
{
	return ((2 * i) + 1);
}
/**
 * right_child - right
 * @i: i
 * Return: int
 */
int right_child(int i)
{
	return ((2 * i) + 2);
}
/**
 * swap - swap function
 * @a: int a
 * @b: int b
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
