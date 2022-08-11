from os import *
from sys import *
from collections import *
from math import *
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
            output.append(arr2[j])
            count+=m-i
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
def getInversions(arr,n):
# Taking inpit using fast I/O.
    out= mergeSort(arr)
    return count
def takeInput() :
    n = int(input())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

# Main.
arr, n = takeInput()
print(getInversions(arr, n))

