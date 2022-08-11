arr = [1,1,1,5]
def addupto(arr,num,upto):
    for i in range(upto):
        arr[i]+=num
addupto(arr,2,3)
print(arr)