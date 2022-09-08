def countPairsWithDiffK(arr, n, k):
    count = 0
    ab = set(arr)
    arr = list(ab)
    n = len(arr)
    # Pick all elements one by one
    for i in range(0, n):
        # See if there is a pair of this picked element
        for j in range(i+1, n) :
             
            if arr[i] - arr[j] == k or arr[j] - arr[i] == k:
                count += 1
                
                 
    return count
 
# Driver program
arr = [1, 5, 3, 4, 2]
arr = [1,1,1,2]
n = len(arr)
k = 1
print ("Count of pairs with given diff is ",
                countPairsWithDiffK(arr, n, k))
