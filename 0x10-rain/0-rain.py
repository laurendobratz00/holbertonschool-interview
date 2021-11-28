#!/usr/bin/python3
# Method that calculates how many square units of water will be retained after it rains

def rain(walls):
    result = 0
    if not walls:
        return 0
    for i in walls:
        maxLeft = 0
        maxRight = 0
        j = 0
        maxLeft = max(maxLeft, walls[j])
        for j in walls:
            maxRight = max(maxRight, walls[j])
        result += min(maxLeft, maxRight) - walls[i]
    return result
