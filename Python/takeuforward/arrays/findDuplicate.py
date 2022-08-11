def findDuplicate(arr:list, n:int):
    # Write your code here.
    # Returns an integer.
    uni = set()
    for num in arr:
        if num in uni:
            return num
        uni.add(num)
    return None

def findDuplicate(arr:list, n:int):
    at = 0
    while(arr[at]!=-1):
        h = at
        at = arr[at-1]
        arr[h]=-1
    return at+1
arr = [1,3,3,4,2]
print(findDuplicate(arr, len(arr)))


