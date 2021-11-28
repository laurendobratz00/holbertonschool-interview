#!/usr/bin/python3
"""calculates how many square units of water retained after it rains"""


def rain(walls):
    """ walls """
    """result = 0
    if not walls:
        return 0
    for i in walls:
        maxLeft = walls[i]
        maxRight = walls[i]
        j = 0
        maxLeft = max(maxLeft, walls[j])
        for j in walls:
            maxRight = max(maxRight, walls[j])
        result += min(maxLeft, maxRight) - walls[i]
    return result"""

    res = 0
    n = len(walls)

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])
        res = res + (min(left, right) - walls[i])
    return res
