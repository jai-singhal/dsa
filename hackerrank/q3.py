# https://www.hackerrank.com/contests/bppc14/challenges/string-and-performing-queries
s = input()
Q = int(input())
for i in range(Q):
    q = [i for i in input().split()]
    if q[0] == "1":
        s = s[::-1] #reverse
    else:
        if q[1] == "1":
            s = q[2] + s
        elif q[1] == "2":
            s = s + q[2]
            
print(s)