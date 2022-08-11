def isMatch(s, p):
    """
    :type s: str
    :type p: str
    :rtype: bool
    """
    i=0
    j=0
    m=len(s)
    n=len(p)
    dot=False
    star=False
    while(i<m and j<n):
        if s[i]==p[j]:
            i+=1
            j+=1
            continue
        if p[j]=='.':
            i+=1
            j+=1
            dot=True
            continue
        if p[j]=="*" and p[j-1]==".":
            i+=1
            continue
        if p[j]=='*':
            if s[i]==s[i-1]:
                i+=1
                continue
            else:
                j+=1
                continue
        if p[j+1]=="*":
            j+=2
            i+=1   
        else:
            return False
    if j<n-1 or i!=m:
        return False
    return True
print(isMatch("aab","c*a*b"))