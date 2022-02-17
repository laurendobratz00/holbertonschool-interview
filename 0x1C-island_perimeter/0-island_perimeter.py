#!/usr/bin/python3
""" function that returns the perimeter of the island described in grid """

def island_perimeter(grid):
    """ returns the perimeter of the island described in grid """
    m = len(grid)
    n = len(grid[0])

    islands = 0
    neighbors = 0

    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                islands += 1
                if i + 1 < m and grid[i + 1][j] == 1:
                    neighbors += 1
                if j + 1 < n and grid[i][j + 1] == 1:
                    neighbors += 1

    return islands * 4 - neighbors * 2
