"""
https://atcoder.jp/contests/dp/tasks/dp_b
"""
import sys

N,K = [int(i) for i in sys.stdin.readline().split(" ")]
arr = [int(i) for i in sys.stdin.readline().split(" ")]

def getMinSteps():
    i = 1
    dp = []
    dp.append({0,})
    while i < N:
        dp.append(set())

        for m in range(i-1, i - min(i, K) - 1, -1):
            temp = list(dp[m])
            for j in range(len(temp)):
                dp[i].add(abs(arr[i] - arr[m]) + temp[j])
        dp[i] = sorted(dp[i])[0:K]
        i += 1
    return min(dp[-1])

        
sys.stdout.write(str(getMinSteps()))