from os import *
from sys import *
from collections import *
from math import *

from sys import stdin,setrecursionlimit

class Solution:
    def __init__ (self, start, end):
        self.start = start
        self.end = end
    def __str__(self):
        return f'({self.start},{self.end})'
def printi(output,st):
    for i in output:
        print(i,end=',')
    print(st)
'''
#unsorted
def mergeIntervals(intervals):
    # Write your code here.
    n = len(intervals)
    output=[]
    count=0
    for i in range(n):
        minat = i
        for j in range(i+1,n):
            if  intervals[j].start < intervals[minat].start:
                minat=j
        intervals[minat],intervals[i] = intervals[i],intervals[minat]
        if count==0:
            output.append(intervals[i])
            count+=1
        elif output[-1].start<=intervals[i].start and output[-1].end>=intervals[i].start:
            output[-1].end=intervals[i].end
        else:
            output.append(intervals[i])
            count+=1
    return output
'''
#sorted       

def mergeIntervals(intervals):
    output=[intervals[0]]

    for interval in intervals[1:]:
        if interval.start>=output[-1].start and interval.start<=output[-1].end:
            output[-1].end=interval.end
        else:
            output.append(interval)
    return output
        
            
    

n = int(input())
arr1 = list(map(int, stdin.readline().strip().split(" ")))
arr2 = list(map(int, stdin.readline().strip().split(" ")))
arr1.sort()
arr2.sort()
intervals = []
for i in range(n):
    a = Solution(arr1[i], arr2[i])
    intervals.append(a)

res = mergeIntervals(intervals)

for i in range(len(res)):
    print(res[i].start, res[i].end)
