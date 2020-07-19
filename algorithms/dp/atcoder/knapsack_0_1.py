"""
https://atcoder.jp/contests/dp/tasks/dp_d
"""
import sys

N,W = [int(i) for i in sys.stdin.readline().split(" ")]
wt = []
val = []
for i in range(N):
    w, v = [int(i) for i in sys.stdin.readline().split(" ")]
    wt.append(w)
    val.append(v)
    
dp = [[0 for i in range(W + 1)] for j in range(N+1)] 

for i in range(1, N + 1):
    for j in range(1, W + 1):
        if wt[i-1] <= j:
            dp[i][j] = max(
                val[i-1] + dp[i-1][j-wt[i-1]],
                dp[i-1][j]
            )
        else:
            dp[i][j] = dp[i-1][j]
    
print(dp[N][W])