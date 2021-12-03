#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the index where value is located
 */

int advanced_binary(int *array, size_t size, int value)
{
	int middle = (size - 1) / 2;
	size_t i = 0;
    int res = 0;

	if (array == NULL || size < 1)
		return (-1);
	print_searching_output(&array[i], size);
	if (array[middle] == value && middle == 0)
		return (middle);
	if (size == 1)
		return (-1);
	if (array[middle] >= value)
		return (advanced_binary(array, middle + 1, value));
	middle++;
	res = advanced_binary(&array[middle], size - middle, value);
	if (res == -1)
		return (-1);
	return (middle + res);
}

/**
* print_searching_output - a helper function to print output
* @array: is a pointer to the first element of the array to search in
* @size: number of elements in array
* Return: void
*/
void print_searching_output(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
		else
			printf("\n");
	}
}
