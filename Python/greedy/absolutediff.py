import sys
arr = [-59,-36,-13,1,-53,-92,-2,-96,-54,75]
def minimumAbsoluteDifference(arr):
    n = len(arr)
    arr.sort()
    minval = None
    for i in range(n-1):
        val = abs(arr[i]-arr[i+1])
        if minval == None:
            minval = val
            continue
        if val < minval:
            minval = val

    return minval

print(minimumAbsoluteDifference(arr))

            


        
