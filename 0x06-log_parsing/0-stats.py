#!/usr/bin/python3
""" a script that reads stdin line by line and computes metrics """
import random
import sys
from time import sleep
import datetime
import fileinput
from sys import argv
import signal
import re

count = 0
l = []
t = (sys.stdin.readline())

while t:
    a = (t.split())
    for i in range(0, (len(a))):
        b = (a[i])
        l.append(b)
    print(l[7:8] + ": ")
    l = []
    t = (sys.stdin.readline())
    count += 1
    if (count % 10 == 0):
        print("File size:", l[8:])
