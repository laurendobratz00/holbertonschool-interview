#!/usr/bin/python3
""" rotate 2D matrix """

def rotate_2d_matrix(matrix):
    """ function to rotate 2D matrix 90 degrees """
    N = len(matrix[0])
    for i in range(N // 2):
        for j in range(i, N - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[N - 1 - j][i]
            matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]
            matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]
            matrix[j][N - 1 - i] = temp
 
# Function to print the matrix
def printMatrix(matrix):
    """ function to print the matrix """
    N = len(matrix[0])
    for i in range(N):
        print(matrix[i])