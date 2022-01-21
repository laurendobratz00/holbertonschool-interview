#!/usr/bin/python3
# Python program to solve N Queen Problem using backtracking
import sys


board = []


def number_of_args():
    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        return None
    n = sys.argv[1]
    return n


def justDoItAlready(n):
    try:
        n = int(n)
    except ValueError:
        print("N must be a number")
        return
    if (n < 4):
        print("N must be at least 4")
        return
#    if type(n) is not int:
#        print("N must be a number")
#        return
    board = getBoard()
    add_queens(len(board))


def getBoard():
    for i in range(int(n)):
        nthList = []
        for j in range(int(n)):
            nthList.append(0)
        board.append(nthList)
    return board


def printBoard():
    for i in range(int(n)):
        for j in range(int(n)):
            print(board[i][j], end=" ")
        print("")


def isSafe(row, col):
    for i in range(int(n)):
        if board[row][i] == 1:
            return False
    for k in range(col):
        if (board[row][i]):
            return False
    for j in range(int(n)):
        if board[j][col] == 1:
            return False
    i = row
    j = col
    while (i >= 0 and j >= 0):
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j - 1
    i = row - 1
    j = col + 1
    while (i >= 0 and j < int(n)):
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j + 1
    i = row + 1
    j = col - 1
    while j >= 0 and i < len(board):
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1
    while (i < int(n) and j >= 0):
        if board[i][j] == 1:
            return False
        i = i + 1
        j = j - 1
    i = row + 1
    j = col + 1

    while (i < int(n) and j < int(n)):
        if board[i][j] == 1:
            return False
        i = i + 1
        j = j + 1
    return True


def Put(n, count):
    if count == int(n):
        return True
    for i in range(int(n)):
        for j in range(int(n)):
            if isSafe(i, j):
                board[i][j] = 1
                count = count + 1
                if Put(int(n), count) is True:
                    return True
                board[i][j] = 0
                count = count - 1
    return False


def add_queens(col):
    if (col == len(board)):
        queens = []
        for row in range(len(board)):
            for column in range(len(board[row])):
                if board[row][column] == 1:
                    queens.append([row, column])
        print(queens)
        return True


if __name__ == '__main__':
    n = number_of_args()
    if (n is not None):
        justDoItAlready(n)
