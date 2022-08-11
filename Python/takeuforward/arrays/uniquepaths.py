'''
def uniquePaths(m,n,i,j):
    if i>=m or j>=n:
        return 0
    if i==m-1 and j==n-1:
        return 1
    return uniquePaths(m,n,i+1,j)+uniquePaths(m,n,i,j+1)
'''

'''
def uniquePaths(m,n):
    if m==1 or n==1:
        return 1
    return uniquePaths(m-1,n)+uniquePaths(m,n-1)
for i in range(1,6):
    print(uniquePaths(i,5))
'''

def uniquePaths(m,n):
    dp = [[1]*n]
    for i in range(1,m):
        k=[]
        for j in range(n):
            if j==0:
                k.append(dp[i-1][j])
            else:
                k.append(k[j-1]+dp[i-1][j])
        dp.append(k)
    return dp[-1][-1]
print(uniquePaths(7,6))

