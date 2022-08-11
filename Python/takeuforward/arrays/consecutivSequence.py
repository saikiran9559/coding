def lengthOfLongestConsecutiveSequence(arr, n):
    # Write your code here.
    arr = list(set(arr))
    arr.sort()
    count=1
    maxval =1
    n = len(arr)
    for i in range(n-1):
        if arr[i+1]-arr[i]==1:
            count+=1
            maxval= max(count,maxval)
        else:
            count=1
    return maxval

arr = [33,20,34,30,35]
arr = [1,0,2,1]
print(lengthOfLongestConsecutiveSequence(arr,len(arr)))
