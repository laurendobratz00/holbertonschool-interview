#!/usr/bin/python3
"""
A method that calculates the fewest number of operations needed to result in exactly n H chars in the file
"""
def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def minOperations(n):
    if n is int:
        if n < 1:
            return 0
        else:
            list = prime_factors(n)
            Sum = sum(list)
            return Sum
