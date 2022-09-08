#recursion memorisation

def fun(arr,n,dp):
    if dp[n]!=-1: return dp[n]
    if n<0: return 0
    if n==0: return arr[0]
    dp[n] = max(
        arr[n] + fun(arr,n-2,dp),
        fun(arr,n-1,dp)
    )
    return dp[n]

def fun(arr,n):
    dp=[-1]*n



arr = [3,5,3,4,7]
dp = [-1]*len(arr)
print(fun(arr,len(arr)-1,dp))
