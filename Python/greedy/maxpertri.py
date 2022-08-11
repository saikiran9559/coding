# sticks = [1,2,3,4,5,10]
sticks = [1,2,3]

def maximumPerimeterTriangle(sticks):
    n = len(sticks)
    sticks.sort()
    for i in range(n-1,1,-1):
        if sticks[i]<sticks[i-1]+sticks[i-2]:
            return [sticks[i-1], sticks[i-2],sticks[i]]
    return [-1]

print(maximumPerimeterTriangle(sticks))