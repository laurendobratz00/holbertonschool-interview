#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - funct that searches for a value in sorted skip list of ints
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: a pointer on the first node where value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *i = list;
	size_t z = 0;

	if (list == NULL)
    {
		return (NULL);
    }

	while (list->n < value)
	{
		z = list->index;
		if (list->express)
        {
			list = list->express;
        }
		else
		{
			while (list->next)
            {
				list = list->next;
            }
			break;
		}
		printf("Value checked at index [%d] = [%d]\n",
			   (int)list->index, list->n);
	}
	printf("Value found between indexes [%d] and [%d]\n",
			(int)z, (int)list->index);
	list = i;
	while (list->index < z)
		list = list->next;
	while (list)
	{
		printf("Value checked at index [%d] = [%d]\n",
			(int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}