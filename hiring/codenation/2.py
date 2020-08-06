def getMinInsertions(firstArray, secondArray):
    mapp = {}
    for i, ele in enumerate(firstArray):
        if ele not in mapp.keys():
            mapp[ele] = [i, ]
        else:
            mapp[ele].append(i)
    
    count = 0
    for i, ele in enumerate(secondArray): 
        if ele not in mapp.keys():
            count += 1
        else:
            if(len(mapp[ele]) != 1):
                # backtrack
                pass
            
    return count


# 1: [4, 5, 1, 8, 4, 8, 7]
# 2: [3, 4, 8, 7]

1: [8, 7, 4]
2: [3, 4, 8, 7]

>o(m*n)

count = 2

3: []
4: [0]
