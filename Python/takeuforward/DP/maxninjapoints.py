
def maxofarr(arr):
    m = arr[0]
    for i in arr[1:]:
        if i>m:
            m=i
    return m
#recursion
def maxninjapoints(arr,at,n):
    if n==-1:
        return 0
    a=0
    b=0
    c=0
    if at!=0:
        a = arr[n][0] + maxninjapoints( arr,0, n-1)
    if at!=1:
        b = arr[n][1] + maxninjapoints( arr,1, n-1)
    if at!=2:
        c = arr[n][2] + maxninjapoints( arr,2, n-1)
    return maxofarr([a,b,c])

def print2D(dp):
    print('[',)
    for i in dp:
        print(i)
    print(']\n')

# recursion with memorization for using sub problems
def maxninjapoints2(arr, at, n, dp):
    print2D(dp)
    if n==-1:
        return 0

    if dp[n][at] != -1:
        return dp[n][at]
    a = 0
    b = 0
    c = 0
    if at!=0:
        a = arr[n][0] + maxninjapoints2( arr, 0, n-1, dp)

    if at!=1:
        b = arr[n][1] + maxninjapoints2( arr, 1, n-1, dp)

    if at!=2:
        c = arr[n][2] + maxninjapoints2( arr, 2, n-1, dp)

    dp[n][at] = maxofarr([a,b,c])
    return dp[n][at]

arr =[
        [3,3,3],
        [3,1,1],
        [1,2,5],
    ]
arr =[
        [2,1,3],
        [3,4,6],
        [10,1,6],
        [8,3,7],
    ]
n = len(arr)
dp= [[-1]*4]*n
print(maxninjapoints(arr,None,n-1))
print(maxninjapoints2(arr,3,n-1, dp))
print2D(dp)
