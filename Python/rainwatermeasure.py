def maxatfun(arr):
    at =0
    n = len(arr)
    if n==0:
        return -1
    for i in range(n):
        if arr[i]>arr[at]:
            at = i
    return at

def measurewater(arr,d):
    if len(arr)==0:
        return 0
    f = None
    to=None
    maxat = maxatfun(arr)
    maxi = arr[maxat]
    if d==1:
        f=0
        to = maxat+1
    else:
        f=maxat+1
        to = len(arr)
    s = 0
    for i in range(f,to):
        s+=maxi-arr[i]
    if d==1:
        return s + measurewater(arr[to:],1)
    else:
        return s + measurewater(arr[:f-1],0)

def rainwater(arr):
    n = len(arr)
    if n <= 2:
        return 0
    left = 0
    right = n-1
    
    while(left<right):
        if arr[left]>arr[right] :
            



arr = [2,0,1,0,3,0,5,0,0,2,4]  
maxat = arr.index(max(arr))
output = measurewater(arr[:maxat],0)+measurewater(arr[maxat+1:],1)


print(output)
