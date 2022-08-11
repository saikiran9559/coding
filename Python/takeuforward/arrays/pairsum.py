count=0
final = []
def insertBefore(arr):
    n = len(final)
    if n==0:
        final.append(arr)
        return
    k=n
    for i in range(n):
        if arr[0]<final[i][0]:
            k=i
            break

        if arr[0]==final[i][0] and arr[1]<final[i][1]:
            k=i
            break
    final.insert(k,arr)

        

def merge(arr1,arr2,s):
    global count,final
    m=len(arr1)
    n=len(arr2)
    output=[]
    i=0
    j=0
    while(i<m and j<n):
        if arr1[i]<=arr2[j]:
            k=j
            while(k<n):
                if arr2[k]+arr1[i]==s:
                    count+=1
                    #final.append([arr1[i],arr2[k]])
                    insertBefore([arr1[i],arr2[k]])
                if arr2[k]+arr1[i]>s:
                    break
                k+=1
            output.append(arr1[i])
            i+=1
        else:
            k=i
            while(k<m):
                if arr1[k]+arr2[j]==s:
                    count+=1
                    #final.append([arr2[j],arr1[k]])
                    insertBefore([arr2[j],arr1[k]])
                if arr1[k]+arr2[j]>s:
                    break
                k+=1
            output.append(arr2[j])
            j+=1
    for k in range(i,m):
        output.append(arr1[k])
    for k in range(j,n):
        output.append(arr2[k])
    return output

def mergeSort(arr,s):
    n = len(arr)
    if n<2:
        return arr
    m = int(n//2)
    return merge(mergeSort(arr[:m],s),mergeSort(arr[m:],s),s)
def pairSum(arr,s):
# Taking inpit using fast I/O.
    global final
    out= mergeSort(arr,s)
    val = final
    final=[]
    return val
def takeInput() :
    n = int(input())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

# Main.
arr = [2,-3,3,3,-2]
arr = [-4,7,-3,4,-8,4,4,0,-6,-7,6,9,3,5,4,-1,-1,-6,-9,0,9,-3,8,5,2,6,2,0,9,-4,-3,0,0,8,4 ]
s = -7
print(pairSum(arr, s))

