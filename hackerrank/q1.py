# https://www.hackerrank.com/contests/bppc14/challenges/another-tricky-question

N = int(input())

arr = [int(i) for i in input().split()]

aii = [arr[i] - i for i in range(N)]
aij = [-1*(arr[i]) - i for i in range(N)]


hmap = {}

for i, a  in enumerate(aii):
    if a in hmap.keys():
        hmap[a].append(i)
    else:
        hmap[a] = [i, ]

count = 0
for i, a  in enumerate(aij):
    if a in hmap.keys():
        count += len(hmap[a])
        if i in hmap[a]:
            count -= 1
            
print(count)       