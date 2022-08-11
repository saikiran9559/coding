x = 3
y = 2
string = "111011"

def abs(val):
    if val<0:
        return -val
    return val
def getval(d,s):
    if d<s:
        return s-1
    else:
        return s+1
def canreach(string,x,y):
    curx = 0
    cury=0
    f=0
    if abs(curx-x) < abs(cury-y):
        f=1
    else:
        f=0
    for i in string:
        if i=='1':
            if f==1:
                cury = getval(y,cury)
            else:
                curx = getval(x,curx)
        else:
            if f==1:
                f=0
                curx = getval(x,curx)
            else:
                f=1
                cury = getval(y,cury)
    if cury == y and curx==x:
        return "YES"
    return "NO"

print(canreach("111011",3,3))