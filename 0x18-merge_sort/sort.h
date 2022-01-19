#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int A[], size_t size, size_t iMiddle, int B[]);
void CopyArray(int *A, int iBegin, int iEnd, int *B);
void TopDownSplitMerge(int B[], int A[], size_t size);

#endif
