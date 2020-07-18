"""
https://atcoder.jp/contests/dp/tasks/dp_c
"""
import sys

N = int(sys.stdin.readline())
input_arr = []
for i in range(N):
    input_arr.append([int(i) for i in sys.stdin.readline().split(" ")])

def getMaxPoints():
    dp = []
    dp.append([
        max(input_arr[0][1], input_arr[0][2]),
        max(input_arr[0][0], input_arr[0][2]),
        max(input_arr[0][0], input_arr[0][1]),
    ])
    for i in range(1, N):
        dp.append(
            [
                input_arr[i][0] + max(dp[i-1][1], dp[i-1][2]),
                input_arr[i][1] + max(dp[i-1][0], dp[i-1][2]),
                input_arr[i][2] + max(dp[i-1][0], dp[i-1][1]),
            ]
        )
        
    return max(dp[-1])
sys.stdout.write(str(getMaxPoints()))