w = [7,5,1,3,2]
p = [8,11,10,5,3]
c = 10
n=5
v=[]


for i in range(n+1):
    m=[]
    for j in range(c+1):
        if(i==0 or j==0):
            m.append(0)
            continue
        if(w[i-1]>j):
            m.append(v[i-1][j])
        else:
            m.append(max(v[i-1][j], v[i-1][j-w[i-1]]+p[i-1]))
    v.append(m)
for i in v:
    print(i)



print(v[n-1][c-1])

def knapsack(wt,val,capacity,n):
    if n==0 or capacity==0:
        return 0
    elif wt[n-1] >capacity:
        return knapsack(wt,val,capacity,n-1)
    else:
        return max(
           val[n-1]+ knapsack(wt,val,capacity-wt[n-1],n-1),
           knapsack(wt,val,capacity,n-1)
        )
print(knapsack(w,p,c,n))

        
        

