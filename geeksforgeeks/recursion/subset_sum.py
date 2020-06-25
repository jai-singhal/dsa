
def subset_sum(arr, l1, l2):
    if len(arr) == 0:
        if l1 == l2 and l1 != 0:
            return 1
        else:
            return 0
    return max(subset_sum(arr[1:], l1 + arr[0], l2), subset_sum(arr[1:], l1, l2 + arr[0]))
        

T = int(input())
while T > 0:
    T = T - 1
    N = int(input())
    lst = list(map(int,input().strip().split()))[:N] 
        
    ret = subset_sum(lst, 0, 0)
    if ret: print("YES")
    else: print("NO")
    