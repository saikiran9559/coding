arr = [[0,1,-1],[1,0,-1],[1,1,1]]
count = 0
n=3
# arr = []
# n = int(input())

def val(a,n,x,y,d,count):
    if(d==0 and a[x][y]==-1):
        return val(a,n,x+1,y,1)
    elif(d==0 and a[x][y]==1):
        a[x][y]=0
        return 1+val(a,x,y+1,0)
    elif(d==1 and a[x][y]==-1):
        return 0

#     for j in range(n):
#         a.append(int(input()))
#     arr.append(a)
# count = 0
# for i in range(1,n-1):
#     for j in range(1,n-1):
#         if(arr[i][j]==1):
#             count+=1
# for i in range(n-1,-1,-1):
#     if(arr[0][i]==-1):
#         break
#     elif(arr[0][i]==1):
#         count+=1

# for i in range(n):
#     if(arr[i][0]==-1):
#         break
#     elif(arr[i][0]==1):
#         count+=1
# for i in range(n):
#     if(arr[i][n-1]==-1):
#         break
#     elif(arr[i][n-1]==1):
#         count+=1

# for i in range(n-1,-1,-1):
#     if(arr[n-1][i]==-1):
#         break
#     elif(arr[n-1][i]==1):
#         count+=1
# print(count)
