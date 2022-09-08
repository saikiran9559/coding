
def partition(arr, low, high):
    i = low
    pivot = arr[low]
    for j in range(low+1,high+1):
        if arr[j]<pivot:
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
    arr[i],arr[low] = arr[low],arr[i]
    return i

def quicksort(arr, low, high):
    if low<high:
        p = partition(arr,low,high)
        quicksort(arr,low,p-1)
        quicksort(arr,p+1,high)

arr = [1,5,6,3,8,2]

quicksort(arr,0,len(arr)-1)
print(arr)

