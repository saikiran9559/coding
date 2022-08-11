arr = [2,4,2,6,1,7,8,9,2,1]
n = len(arr)
# def candies(n, arr):
#     total= n
#     prev = 1
#     grt_at = 1
#     grt_val = 0
#     output = [1]*n
#     for i in range(1,n):
#         if arr[i] < arr[i-1]:
#             if(prev==1):
#                 if i-grt_at >=grt_val:
#                     grt_val+=1
#                     total+=1
#                 total+=i-grt_at-1
#             prev=1
#         elif arr[i] > arr[i-1]:
#             grt_at = i
#             grt_val = prev+1
#             total +=prev
#             prev+=1
#         elif prev>1:
#             total+=i-grt_at
            
#     return total


def candies(n,arr):
    output = [1]*n
    grt_at = 1
    for i in range(n-1):
        le = arr[i]
        ri = arr[i+1]
        if le < ri:
            output[i+1] = output[i]+1
        elif le > ri:
            if output[i] == 1:
                output[i]+=1
                for j in range(i,-1,-1):
                    if arr[]
            else:
                output[i+1]=1


print(candies(n,arr))


        
