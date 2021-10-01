#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * slide_line - a function that slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: elements to be slid and merged
 * @direction: direction
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int i, position = 0;

	if ((direction != SLIDE_RIGHT && direction != SLIDE_LEFT) || (size <= 0))
	{
		return (0);
	}
	if (direction == SLIDE_LEFT)
	{
		for (i = 1; i < (int)size; i++)
		{
			if (line[i] && line[i] == line[position])
			{
				line[position++] += line[i];
				line[i] = 0;
			}
			else if (line[i] && line[i] != line[position])
			{
				if (line[position] != 0)
					position++;
				else
				{
					line[position] += line[i];
					line[i] = 0;
				}
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		position = size - 1;
		for (i = size - 2; i >= 0; i--)
		{
			if (line[i] && line[i] == line[position])
			{
				line[position--] += line[i];
				line[i] = 0;
			}
			else if (line[i] && line[i] != line[position])
			{
				if (line[position] != 0)
					position--;
				else
				{
					line[position] += line[i];
					line[i] = 0;
				}
			}
		}
	}
	return (1);
}