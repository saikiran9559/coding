from math import factorial as fact
from copy import deepcopy
arr = list("1234")
count =0
k=9
item = "012345"
at = 2
i =4
def replace(item, i,j,n):
    li = ""
    for m in range(n):
        if m==i:
            li+=item[j]
            li+=item[m]
            continue
        if m==j:
            continue
        li+=item[m]
    return li
print(replace(item,2,4,6))
def permutate(arr,start,end):
    global count
    if start==end:
        count+=1
        print(count-1,arr)
        print()
        return
    for i in range(start,end+1):
        arr[i],arr[start] = arr[start],arr[i]
        permutate(arr,start+1,end)
        arr[i],arr[start] = arr[start],arr[i]

def getPermutation(n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        item=""
        for i in range(n):
            item+=str(i+1)
        k-=1
        w = fact(n)//n
        at = 0
        while(at<n-1):
            rem = int(k//w)
            if rem==0 and k%w==0:
                break
            # li[at+rem],li[at] = li[at],li[at+rem]
            if rem!=0:
                item = replace(item,at,at+rem,n)
            k = k%w
            at+=1
            w = fact(n-at)/(n-at)
        return item

print(getPermutation(3,5))