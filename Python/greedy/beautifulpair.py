# A = [3,5,7,11,5,8]
# B = [5,7,11,10,5,8]
A=[1]
B=[1]
def beautifulPairs(A, B):
    # Write your code here
    A.sort()
    B.sort()
    n = len(A)
    i=0
    j=0
    count=0
    while(i<n and j<n):
        if A[i]<B[j]:
            i+=1
        elif A[i]>B[j]:
            j+=1
        else:
            count+=1
            i+=1
            j+=1
    if count<n:
        return count+1
    else:
        return count-1


print(beautifulPairs(A,B))