"""
https://atcoder.jp/contests/dp/tasks/dp_b
"""
import sys

N,K = [int(i) for i in sys.stdin.readline().split(" ")]
arr = [int(i) for i in sys.stdin.readline().split(" ")]

def getMinSteps():
    i = 0
    dp = [-1]*N
    dp[0] = 0
    for i in range(N):
        for j in range(i+1,min(i+1+K,N)):
            if j >= N:
                break
            if dp[j] == -1:
                dp[j] = dp[i] +  abs(arr[j]- arr[i])
            else:
                dp[j] = min(dp[j], dp[i]+ abs(arr[j]- arr[i]))
    return dp[-1]

sys.stdout.write(str(getMinSteps()))