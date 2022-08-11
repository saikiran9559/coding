def printPascal(n:int):
    # Write your code here.
    # Return a list of lists.
    output=[[1]]
    for i in range(1,n):
        re=[]
        for j in range(i+1):
            if j==0:
                re.append(output[i-1][0])
                continue
            if j==i:
                re.append(output[i-1][-1])
                continue
            re.append(output[i-1][j-1]+output[i-1][j])
        output.append(re)
    return output
for i in range(1,5):
    print(printPascal(i))