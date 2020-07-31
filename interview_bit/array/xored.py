N = int(input())
K = int(input())
M = int(input())
arr = [int(i) for i in input().split()]

def get_nCr(n, r): 
    p = 1
    k = 1
    if (n - r < r): 
        r = n - r 
    if (r != 0):  
        while (r): 
            p *= n 
            k *= r 
            m = gcd(p, k) 
            p //= m 
            k //= m 
            n -= 1
            r -= 1
    else: 
        p = 1
    return p 
  

result = arr[M]
for i, ii in enumerate(range(M+1, M+K+2)):
    if get_nCr(k, i+1) % 2 == 1:
        result = result ^ arr[ii]
    
print(result)