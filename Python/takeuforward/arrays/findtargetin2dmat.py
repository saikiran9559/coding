def find(arr,target):
    i=0
    n=len(arr)-1
    while(i<=n):
        m = (i+n)//2
        if arr[m]==target:
            return True
        if arr[m]<target:
            i=m+1
        else:
            n=m-1
    return False

def findTargetInMatrix(mat, m, n, target):
    row=0
    m-=1
    while(row<m):
        mid=(row+m)//2
        if mat[mid][0]==target or mat[mid][-1]==target:
            return True
        if mat[mid][0]<target and mat[mid][-1]>target:
            row = mid
            break
        if mat[mid][0]<target:
            row = mid+1
        else:
            m = mid-1
    column=0
    n-=1
    while(column<=n):
        mid=(column+n)//2
        if mat[row][mid]==target:
            return True
        if mat[row][mid]<target:
            column = mid+1
        else:
            n = mid-1
    return False
    
# mat = [
#     [1,2,3,4,5],
#     [6,7,9,10,11],
#     [12,13,14,15,16]
# ]
t = int(input())
for _ in range(t):
    val = list(map(int,input().split()))
    m,n,target = val[0],val[1],val[2]
    mat=[]
    for _ in range(m):
        mat.append(list(map(int,input().split())))
    print(findTargetInMatrix(mat,m,n,target))
# print(findTargetInMatrix(mat,len(mat),len(mat[0]),10))

                




	