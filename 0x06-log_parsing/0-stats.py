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

if __name__ == '__main__':
    try:
        count = 0
        l = []
        t = (sys.stdin.readline())
        input = t.rstrip()
        statuscodecount = 0
        while t:
            a = (t.split())
            for i in range(0, (len(a))):
                b = (a[i])
                l = []
                l = l.append(b)
                statuscode = int(input.rsplit(' ', 2)[1])
                print(str(statuscode) + ": " + str(statuscodecount))
                statuscodecount += 1
                count += 1
                if (count % 10 == 0):
                    filesize = int(input.rsplit(' ', 1)[1])
                    print("File size:", filesize)
    except KeyboardInterrupt as err:
        pass
