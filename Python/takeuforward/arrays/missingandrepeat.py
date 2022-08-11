from os import *
from sys import *
from collections import *
from math import *

def missingAndRepeating(arr, n):
    # Write your code here
    s=0
    uni = set()
    repeat = None
    for num in arr:
        if num in uni:
            repeat = num
            continue
        s+=num
        uni.add(num)
    missing = int(((n+1)*n)/2) - s
    print(""+missing+" "+repeat)

t = int(input())
arrs = []
lens=[]
for _ in range(t):
    lens.append(int(input()))
    arr = list(map(int,input().split()))
    arrs.append(arr)

for i in range(t):
    missingAndRepeating(arrs[i],lens[i])
