#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sandpiles.h"

/**
 * add - adds two sandpiles, separated for betty <3
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 * Return: sum
 */
void add(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
        }
    }
}

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * @grid1: 1st pile
 * @grid2: 2nd pile
 * Return: sum of 2 sandpiles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, z, newGrid[3][3];

    add(grid1, grid2);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            newGrid[i][j] = grid1[i][j];
        }
    }
    z = check_stable(grid1);
    while (z == 1)
    {
        printf("=\n");
        print_grid1(grid1);
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] >= 4)
                    newGrid[i][j] -= 4;
                if (i != 0 && grid1[i - 1][j] >= 4)
                    newGrid[i][j]++;
                if (i != 2 && grid1[i + 1][j] >= 4)
                    newGrid[i][j]++;
                if (j != 0 && grid1[i][j - 1] >= 4)
                    newGrid[i][j]++;
                if (j != 2 && grid1[i][j + 1] >= 4)
                    newGrid[i][j]++;
            }
        }
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                grid1[i][j] = newGrid[i][j];
            }
        }
        z = check_stable(grid1);
    }
}

/**
 * check_stable - computes sum
 * @grid1: sandpile 1
 * Return: sum
 */
int check_stable(int grid1[3][3])
{
    int i, j, num;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            num = grid1[i][j];
            if (num >= 4)
            {
                return (1);
            }
        }
    }
    return (0);
}

/**
 * printgrid1 - function from main file that prints grid
 * @grid: sandpile
 * Return: void
 */
void print_grid1(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
