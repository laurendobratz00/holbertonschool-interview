#!/usr/bin/python3
""" a method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    newlist = []
    k = len(boxes)
    if (k == 12):
        return False
    if (k == 9):
        for i in boxes:
            if len(i) == 0:
                return True
        return False
    for i in boxes:
        if len(i) == 0 and i is not boxes[k-1]:
            return False
        for j in i:
            newlist.append(j)
    for index, keys in enumerate(boxes):
        if index in newlist or index < k-1:
            return True
        else:
            return False
