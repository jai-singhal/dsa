from math import factorial

def myfun(input1, input2):
    mod = 10**4
    a = input1
    b = input2
    empty_pos = a+1
    extra_last = b-2*a+1
    if extra_last > 0:
        x = factorial(empty_pos)//(factorial(empty_pos)*factorial(extra_last-1))
        ans = ((factorial(a))%mod)*(empty_pos%mod)*(x%mod)
    else:
        ans = (factorial(a))%mod

    return ans%mod
