def maxSubarraySum(arr, n) :

	# Your code here
    # return the answer
    maxi = arr[0]
    subsum=maxi
    for i in arr[1:]:
        subsum+=i
        if i > subsum:
            maxi=i 
            subsum=i
        if subsum>maxi:
            maxi=subsum
    if maxi<0:
        return 0
    return maxi
arr=[10,20,-30,40,-50,60]
# arr=[1,2,7,-4,3,2,-10,9,1]
# arr=[-7,-8,-16,-4,-8,-5,-7,-11,-10,-12,-4,-6,-4,-16,-10]

print(maxSubarraySum(arr,len(arr)))