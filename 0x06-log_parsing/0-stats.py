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
        statuscodecount = 0
        count200 = 0
        count301 = 0
        count400 = 0
        count401 = 0
        count403 = 0
        count404 = 0
        count405 = 0
        count500 = 0
        for t in sys.stdin:
            input = t.rstrip()
            statuscode = int(input.rsplit(' ', 2)[1])
            a = (t.split())
            try:
                filesize = int(input.rsplit(' ', 1)[1])
            except IndexError:
                pass
            if (statuscode == 200):
                count200 += 1
                print("200:", count200)
            if (statuscode == 301):
                count301 += 1
                print("301:", count301)
            if (statuscode == 400):
                count400 += 1
                print("400:", count400)
            if (statuscode == 401):
                count401 += 1
                print("401:", count401)
            if (statuscode == 403):
                count403 += 1
                print("403:", count403)
            if (statuscode == 404):
                count404 += 1
                print("404:", count404)
            if (statuscode == 405):
                count405 += 1
                print("405:", count405)
            if (statuscode == 500):
                count500 += 1
                print("500:", count500)
        if (count % 10 == 0):
            print("Filesize:", filesize)
        for i in range(0, (len(a))):
            b = (a[i])
            l = []
            l = l.append(b)
            if (statuscode == 200):
                statuscodecount += 1
            if (statuscode == 301):
                statuscodecount += 1
            if (statuscode == 400):
                statuscodecount += 1
            if (statuscode == 401):
                statuscodecount += 1
            if (statuscode == 403):
                statuscodecount += 1
            if (statuscode == 404):
                statuscodecount += 1
            if (statuscode == 405):
                statuscodecount += 1
            if (statuscode == 500):
                statuscodecount += 1
            count += 1
    except KeyboardInterrupt as err:
        pass
