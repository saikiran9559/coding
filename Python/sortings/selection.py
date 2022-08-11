array = [3,5,1,9,2]
n = len(array)
for i in range(n-1):
    min_index = i
    for j in range(i+1,n):
        if(array[min_index] > array[j]):
            min_index = j
    array[min_index], array[i] = array[i], array[min_index]
print(array)
