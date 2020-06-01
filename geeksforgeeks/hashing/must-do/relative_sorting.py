T = int(input())
while T:
    T -= 1
    N, M = (int(i) for i in input().split(" "))
    arr_n = [int(i) for i in input().split(" ")]
    arr_m = [int(i) for i in input().split(" ")]
    
    order = dict()
    for elm in arr_m:
        order[elm] = 0
        
    not_in_order = list()
    
    for elm in arr_n:
        if elm in order.keys():
            order[elm] += 1
        else:
            not_in_order.append(elm)
    
    for key in arr_m:
        for i in range(order[key]):
            print(key, end = " ")
            
    not_in_order.sort()
    for i in not_in_order:
        print(i, end = " ")
            
    print()
    
    