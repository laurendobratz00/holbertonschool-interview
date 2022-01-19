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

	B = malloc(sizeof(int) * size);
	CopyArray(array, 0, size, B);
	TopDownSplitMerge(array, B, size);
	free(B);
}
/**
 * TopDownSplitMerge - split merge
 * @B: array
 * @iBegin: left
 * @iEnd: right
 * @A: array
 * Return: void
 */

void TopDownSplitMerge(int B[], int A[], size_t size)
{
	int iMiddle = 0;

	if (size < 2)
	{
		return;
	}
	iMiddle = size / 2;

	TopDownSplitMerge(A, B, iMiddle);
	TopDownSplitMerge(A + iMiddle, B, size - iMiddle);
	merge(B, size, iMiddle, A);
}
/**
 * merge - merges two subarrays
 * @A: array
 * @iBegin: left
 * @iMiddle: middle
 * @iEnd: right
 * @B: copied array
 * Return: void
 */

void merge(int A[], size_t size, size_t iMiddle, int B[])
{
	size_t i = 0, j = iMiddle, k = 0;

	for (i = 0; k < size; k++)
	{
		if (i < iMiddle && (j == size || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
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
