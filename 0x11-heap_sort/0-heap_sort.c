#include "sort.h"

/**
 * heap_sort - func that sorts an array of integers using Heapsort alg
 * @array: int
 * @size: size_t
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;
	int swap;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = (size / 2) - 1; i >= 0; i--)
	{
		down(array, size, i, size);
	}
	for (i = (size - 1); i > 0; i--)
	{
		swap = array[0];
		array[0] = array[i];
		array[i] = swap;
		if (i != 0)
		{
			print_array(array, size);
		}
		down(array, i, 0, size);
	}
}

/**
 * down - func that sorts an array of integers using Heapsort alg
 * @arr: int
 * @size: size_t
 * @i: size_t
 * @copy_size: size_t
 * Return: void
 */

void down(int *arr, size_t size, size_t i, size_t copy_size)
{
	size_t left, right, copy;
	int temp = 0;

	left = 2 * i + 1;
	right = 2 * i + 2;
	copy = i;
	if (left < size && arr[left] > arr[copy])
	{
		copy = left;
	}
	if (right < size && arr[right] > arr[copy])
	{
		copy = right;
	}
	if (copy != i)
	{
		temp = arr[i];
		arr[i] = arr[copy];
		arr[copy] = temp;
		print_array(arr, copy_size);
		down(arr, size, copy, copy_size);
	}
}
