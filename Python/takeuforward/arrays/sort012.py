def sort012(arr, n):
    ones = 0
    twos=0
    for i in arr:
        if i==0:
            print(i,end=' ')
            continue
        if i==1:
            ones+=1
            continue
        if i==2:
            twos+=1
    for _ in range(ones):
        print(1,end=' ')
    for _ in range(twos):
        print(2,end=' ')
    print()
arr=[2,1,0,2,0,0,2]
sort012(arr,len(arr))