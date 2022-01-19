#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - sorts array of ints in ascending order using Merge Sort alg
 * @array: array
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *B = NULL;

	if (array && size > 1)
	{
		B = malloc(sizeof(int) * size);
		CopyArray(array, 0, size, B);
		TopDownSplitMerge(array, B, size);
		/* merge_sort(array, size) */
		free(B);
	}
}
/**
 * TopDownSplitMerge - split merge
 * @B: array
 * @A: array
 * @size: size of array
 * Return: void
 */

void TopDownSplitMerge(int A[], int B[], size_t size)
{
	int iMiddle = 0;

	if (size < 2)
	{
		return;
	}
	iMiddle = size / 2;

	TopDownSplitMerge(A, B, iMiddle);
	TopDownSplitMerge(A + iMiddle, B, size - iMiddle);
	merge(A, B, size);
}
/**
 * merge - merges two subarrays
 * @A: array
 * @size: size of array
 * @iMiddle: middle
 * @B: copied array
 * Return: void
 */

void merge(int A[], int B[], size_t size)
{
	size_t iMiddle = size / 2;
	size_t i = 0, j = iMiddle, k = 0;

	printf("Merging...\n[left]: ");
	print_array(A, iMiddle);
	printf("[right]: ");
	print_array(A + iMiddle, size - iMiddle);
	for (i = 0; k < size; k++)
	{
		if (i < iMiddle && (j == size || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}
	for (i = 0; i < size; i++)
	{
		A[i] = B[i];
	}
	printf("[Done]: ");
	print_array(B, size);
}
/**
 * CopyArray - makes a copy of an array
 * @A: array to copy
 * @iBegin: left
 * @iEnd: right
 * @B: copy of original array
 * Return: void
 */

void CopyArray(int *A, int iBegin, int iEnd, int *B)
{
	int k;

	for (k = iBegin; k < iEnd; k++)
	{
		B[k] = A[k];
	}
}
