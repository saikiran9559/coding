from os import *
from sys import *
from collections import *
from math import *

def getInversions(arr,n):
    count=0
    for i in range(n-1):
        for j in range(i+1,n):
            if arr[i]>arr[j]:
                count+=1
    return count
# Taking inpit using fast I/O.
def takeInput() :
    n = int(input())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

# Main.
arr, n = takeInput()
print(getInversions(arr, n))