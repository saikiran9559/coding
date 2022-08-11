def rotateMatrix(mat, n, m):

    # Write your code here
    # n,k rows , m,p columns
    k=0
    while(n-k>2 and m-k>2):
        topright = mat[k][m-k-1]
        bottomleft = mat[n-k-1][n]
        for i in range(m-k-1,k,-1):
            mat[k][i] = mat[k][i-1]
            mat[n-k-1][m-i-1]=mat[n-k-1][m-i]
        for i in range(k,n-1):
            mat[i][k]=mat[i+1][k]
            mat[n-i-1][m-k-1] = mat[n-i][m-k-1]
        mat[k+1][m-k-1]=topright
        mat[n-k-2][k] = bottomleft
        k+=1
    return mat

print(rotateMatrix())


            








