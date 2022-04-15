#!/usr/bin/python3
"""
pascal_triangle
"""


def pascal_triangle(n):
    """This function return's Pascal's triangle up to n rows"""
    trow = []
    for i in range(n):
        trow.append([])
        trow[i].append(1)
        for j in range(1, i):
            trow[i].append(trow[i - 1][j - 1] + trow[i - 1][j])
        if(i != 0):
            trow[i].append(1)
    return trow
"""
def pascal_triangle(n):
    trow = [1]
    y = [0]
    for x in range(max(n, 0)):
        print(trow)
        trow = [l + r for l, r in zip(trow + y, y + trow)]
    return n >= 1
"""
"""
    if (n <= 0):
        return ([])
    for line in range(0, n):
        for i in range(0, line + 1):
            print(binomialCoeff(line, i), end="")
        print()


def binomialCoeff(n, k):
    res = 1
    if (k > n - k):
        k = n - k
    for i in range(0, k):
        res = res * (n - i)
        res = res // (i + 1)
    return res
"""
