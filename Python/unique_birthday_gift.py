import math
n = 6
k = 3
def factorial(n):
    if(n==0):
        return 1
    return n * factorial(n-1)

def ncr(n,r):
    return math.factorial(n)/(math.factorial(r)*math.factorial(n-r))
count = int(ncr(k+1,1))*(n-1) - n-2
print(count)

for i in range(2,n+1):
    num = int(math.log(int(n/i),2))
    print(i,num)
    if(num>0):
        count += ncr(k-2+num-1, num-1)
    
print(count)
