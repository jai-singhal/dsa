"""
https://atcoder.jp/contests/dp/tasks/dp_a
"""
from copy import deepcopy
N = int(input())
arr = [int(i) for i in input().split(" ")]

def getMinSteps():
    dp_2 = [0, ]
    dp_1 = [abs(arr[1] - arr[0]), ]
    
    i = 2
    
    while i < N:
        diff1 = abs(arr[i] - arr[i-1])
        diff2 = abs(arr[i] - arr[i-2])
        temp = deepcopy(dp_2)
        dp_2 = deepcopy(dp_1)

        for j in range(len(dp_1)):
            dp_1[j] += diff1

        for j in range(len(temp)):
            dp_1.append(temp[j] + diff2)
            
        dp_1 = sorted(dp_1)[0:2]
        
        i += 1
    return min(dp_1)

        
print(getMinSteps())