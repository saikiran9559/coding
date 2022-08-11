types= 4
n = 10
c = [2,5,3,6]
c.sort()
print(c)
count =0
# def getWays(n,c,j,types):
#     global count
#     if(n==0):
#         count+=1
#     else:
#         for i in range(j,types):
#             if(n-c[i]>=0):
#                 getWays(n-c[i],c,i,types)
#             else:
#                 break
# getWays(n,c,0,types)

# def getWays(n,c,j,types):
#     global count
#     for i in range(j,types):
#         if c[i]>n:
#             break
#         rem = n%c[i]
#         if(rem==0):
#             count+=1
#             getWays(n-c[i],c,i+1,types)
#         else:
#             getWay(n-c[i]-rem,c,i+1,types)
        
# getWays(n,c,0,types)
dp = [1]+[0]*n
for i in c: 
    for j in range(i, n+1): 
        dp[j]+=dp[j-i]
        print(i,j,dp)
print(dp[-1])
# print(count)

    
