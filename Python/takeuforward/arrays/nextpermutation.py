def nextPermutation(p, n):
    # Write your code here.
    # Return a list.
    if p[n-1]>p[n-2]:
        p[n-1],p[n-2]=p[n-2],p[n-1]
        return p

    for i in range(n-1,0,-1):
        if p[i]<p[i-1]:
            continue
        if p[i-1]>p[i+1]:
            p[i],p[i-1]=p[i-1],p[i]
        else:
            p[i-1],p[i+1]=p[i+1],p[i-1]
        k=0
        for i in range(i,int((n+i)/2)):
            p[i],p[n-k-1]=p[n-k-1],p[i]
            k+=1
        return p
    return p[::-1]

p = [5,3,2,4,1]
print(nextPermutation(p,len(p)))