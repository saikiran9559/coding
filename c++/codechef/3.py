t = int(input())
while(t):
    t-=1
    n,k = map(int,input().split())
    if(n<=k):
        print("NO")
        continue
    s = (k*(k+1))/2
    if(s<=n):
        print("YES")
    else:
        print("NO")
