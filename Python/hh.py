n = int(input())
arr =[]
for i in range(n):
    arr.append(int(input()))
l = int(input())
r = int(input())
count = 0
for i in range(n):
    for j in range(i+1,n):
        if(arr[i]+arr[j] >= l and arr[i]+arr[j]<=r):
            count+=1
print(count)