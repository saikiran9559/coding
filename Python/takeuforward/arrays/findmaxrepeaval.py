def findMajorityElement(arr, n):
	# Write your code here.
    d = {}
    val =set()
    sc=0
    gc=0
    gval=arr[0]
    for i in arr:
        if i not in val:
            val.add(i)
            d[i]=0
        d[i]+=1
        c = d[i]
        if c==gc:
            sc=1
        elif c>gc:
            sc=0
            gc=c
            gval=i
    if sc==0 and gc>n//2:
        return gval
    return -1

#arr = [1,2,2,2,3,1,1,1]
arr=[10]
print(findMajorityElement(arr,len(arr)))



