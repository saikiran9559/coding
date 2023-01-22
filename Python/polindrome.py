def polindrome(cls, input1):
    i=0
    j = len(input1)-1
    while(i<j):
        if(input1[i]!=input1[j]):
            break
        i+=1
        j-=1
    if(i>=j):
        return 1
    else:
        return 0

