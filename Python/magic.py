import math
n = 5
k = 3
a = [39,43,47,37,48]

def fun(n,k,a):
    for i in range(n):
        v = pow(k,i)
        if a[i]%v!=0:
            return "NO"
    return "YES"

print(fun(n,k,a))

