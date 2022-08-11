w = [1,2,3,21,7,12,14,21]

def toys(w):
    n = len(w)
    w.sort()
    minval = w[0]
    count = 1
    for i in range(1,n):
        if w[i] > minval+4:
            minval=w[i]
            count+=1
    return count

print(toys(w))

        
        