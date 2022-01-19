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
	TopDownSplitMerge(B, 0, size, array);
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

void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	int iMiddle = 0;

	if (iEnd - iBegin <= 1)
	{
		return;
	}
	iMiddle = (iEnd + iBegin) / 2;

	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	merge(B, iBegin, iMiddle, iEnd, A);
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

void merge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin, j = iMiddle, k;

	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
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
