nk = input().split()
n = int(nk[0])
k = int(nk[1])
arr = list(map(int,input().rstrip().split()))

# arr = [1,3,5,7,9]

# k =3

def getMinimumCost(k,arr):
    arr.sort(reverse=True)
    n = len(arr)
    mul=1
    val =0
    for i in range(0,n):
        val+=arr[i]*mul
        if i%k==k-1:
            mul+=1
    return val

print(getMinimumCost(k,arr))
        


    