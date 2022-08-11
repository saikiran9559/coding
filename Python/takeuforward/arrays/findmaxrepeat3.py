
def majorityElementII(arr):
    # Write your code here.
    n = len(arr)
    d = {}
    val =set()
    sc=0
    gc=0
    gval=arr[0]
    output=set()
    for i in arr:
        if i not in val:
            val.add(i)
            d[i]=0
        d[i]+=1
        c = d[i]
        if c>n//3:
            output.add(i)
    if len(output)>0:
        return list(output)
    return -1

#arr = [2,2,2,5,5]
#arr = [1,2,4,4,3,4]
#arr = [4,3,9,3,3,4,4,7]
arr=[7,8,9,7,3,7,7,8,8,9]
print(majorityElementII(arr))
