#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void down(int *arr, size_t size, size_t i, size_t copy_size);

#endif
