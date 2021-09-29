#!/usr/bin/python3
""" a script that reads stdin line by line and computes metrics """
import random
import sys
from time import sleep
import datetime
import fileinput


t = int(sys.stdin.readline())
# To store input here
l = [] 
 
while t: 
	#To store the size of array here
	n = int(sys.stdin.readline()) 
	#using sys.stdin.readline() to take input then split
	a = (sys.stdin.readline().split()) 
	#Now converting
	for i in range(0, n): 
		b = int(a[i]) 
		l.append(b) 
	print (l) 
	l = [] #empty list for next input
	t = t - 1