from copy import deepcopy
xcost=[2,1,3,1,4]
ycost = [4,1,2]
# xcost=[2]
# ycost=[1]
xcost.sort(reverse=True)
ycost.sort(reverse=True)
x = len(xcost)
y = len(ycost)
def boardCutting1(xcost, ycost,x,y):
    m = len(xcost)
    n = len(ycost)
    xsum = sum(xcost)
    ysum = sum(ycost)

    # print(xcost,"sum=",xsum,ycost,"sum=",ysum)
    if m==0:
        # print("y",ysum*(x+1))
        return ysum*(x+1)
    elif n==0:
        # print("x",xsum*(y+1))
        return xsum*(y+1)
    xcost1 = xcost[1:]
    ycost1 = ycost[1:]
    xval = xcost[0]*(y-n+1)+boardCutting1(xcost1,ycost,x,y)
    yval = ycost[0]*(x-m+1)+boardCutting1(xcost,ycost1,x,y)
    # print("x,y,best",xval,yval,min(xval,yval))
    return min(xval,yval)

print(boardCutting1(xcost,ycost,x,y))







