from pprint import pprint

def printBoard(arr):
    for row in arr:
        for col in row:
            print(col, end = " ")
        print("") 


def isSafe(arr, row, col, N):
    for i in range(col):   
        if arr[row][i] == 1:
            return False

    for i,j in zip(range(row, -1, -1), range(col, -1, -1)):  #diagonal check
        if arr[i][j] == 1:
            return False
    
    for i, j in zip(range(row, N, 1), range(col, -1, 1)): # other diagonal check
        if arr[i][j] == 1:
            return False

    return True


def nQueenProblem(arr, col, N):
    if col >= N:
        return True

    for i in range(N):
        if isSafe(arr, i, col, N):
            arr[i][col] = 1  

            if nQueenProblem(arr, col+1, N):
                return True

            arr[i][col] = 0 #backtrack
       
    return False


def main():
    N = 8
    arr = [[0 for row in range(N)] for col in range(N)]
    nQueenProblem(arr, 0, N)
    printBoard(arr)

if __name__ == "__main__":
    main()
