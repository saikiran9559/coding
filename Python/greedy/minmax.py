arr = [100,200,300,350, 400, 401, 402]
k=3
def maxMin(k, arr):
    # Write your code here
    n = len(arr)
    arr.sort()
    minval = None
    for i in range(n-k+1):
        val = abs(arr[i]-arr[i+k-1])
        print(val)
        if minval == None:
            minval = val
            continue
        if val < minval:
            minval = val
    return minval
print(maxMin(k,arr))