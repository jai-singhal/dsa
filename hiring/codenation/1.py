def stringReduction(k, s):
    to_remove = []
    for i in range(len(s) - 1, 1, -1):
        if(s[i] < s[i-1]):
            to_remove.append(i)
    
    to_remove = to_remove[:k]
    news = ""
    for i in s:
        if i not in to_remove:
            news += i
    print(news)
    
stringReduction(2, "zyxedcb")
