def getDigits(n):
    return len(str(n))

def binarySearch (l, r, A, B, maxSol): 
    # print(l, r, A, B, maxSol, sol)
    i = l
    while True:
        sol = A*i + B*getDigits(i)
        if sol < maxSol: 
            i = i*2
        else:
            break
    return i//2, sol
    
A,B,X = [int(i) for i in input().split()]
mid, maxsol = binarySearch(1, X, A, B, X)
print(mid)
for i in range(mid*2, mid, -1):
    sol = A*i + B*getDigits(i)
    if sol > maxsol:
        maxsol = sol
    else:
        print(i-1)
        break    