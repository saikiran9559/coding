count=0
def merge(arr1,arr2):
    global count
    m=len(arr1)
    n=len(arr2)
    output=[]
    i=0
    j=0
    while(i<m and j<n):
        if arr1[i]<=arr2[j]:
            output.append(arr1[i])
            i+=1
        else:
            k=i
            while(k<m):
                if arr1[k]>2*arr2[j]:
                    count+=m-k
                k+=1
            output.append(arr2[j])
            j+=1
    for k in range(i,m):
        output.append(arr1[k])
    for k in range(j,n):
        output.append(arr2[k])
    return output

def mergeSort(arr):
    n = len(arr)
    if n<2:
        return arr
    m = int(n//2)
    return merge(mergeSort(arr[:m]),mergeSort(arr[m:]))
def reversePairs(arr,n):
# Taking inpit using fast I/O.
    out= mergeSort(arr)
    return count
def takeInput() :
    n = int(input())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

# Main.
#arr = [6,4,8,2,1,3]
arr = [2,4,3,5,1]
arr = [7,3,1,4,4,3,0,6 ]
print(reversePairs(arr, len(arr)))

