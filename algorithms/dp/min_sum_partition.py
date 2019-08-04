"""
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
In each seperate line print minimum absolute difference.

Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50

Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11},       sum of Subset2 = 11
"""

def minSumPartition(arr, n):
    if n == 0:
        return 0
    # print(arr, n)
    return (arr[0] + minSumPartition(arr[1:], n-1)) - minSumPartition(arr[1:], n-1)
    # print("Min Val", min_val)

print(minSumPartition([36, 7, 46, 40], 4))