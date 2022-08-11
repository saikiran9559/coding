'''
method1
def ninjaAndSortedArrays(arr1,arr2,m,n):
    # Write your code here.
    i=0
    j=0
    while(i<m and j<n):
        if arr2[j] < arr1[i]:
            for k in range(m,i,-1):
                arr1[k]=arr1[k-1]
            arr1[i]=arr2[j]
            j+=1
            m+=1
        i+=1
    for k in range(j,n):
        arr1[m]=arr2[k]
        m+=1
    return arr1
'''

def ninjaAndSortedArrays(arr1,arr2,m,n):
    output=[]
    i=0
    j=0
    while(i<m and j<n):
        if arr1[i]<=arr2[j]:
            output.append(arr1[i])
            i+=1
        else:
            output.append(arr2[j])
            j+=1
    for k in range(j,n):
        output.append(arr2[k])
    for k in range(i,m):
        output.append(arr1[k])
    return output
        

m=4
n=2
arr1=[1,4,6,10,0,0]
arr2=[2,5]
print(ninjaAndSortedArrays(arr1,arr2,m,n))

    
