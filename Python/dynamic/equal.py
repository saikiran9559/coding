arr = [1,1,5]
def equal(arr):
    # Write your code here
    n = len(arr)
    arr.sort()
    count=0
    for j in range(0,n-1):
        print(count)
        dif = arr[j+1]-arr[j]
        if(dif==0):
            continue
        if(dif==1 or dif==2):
            count+=1
            continue
        elif dif < 5 :
            count+2
            continue
        rem = arr[j]%5
        if rem == 0:
            count+=arr[j]//5
        else:
            count+= (arr[j]//5)+2
    return count
print(equal(arr))