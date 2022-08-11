n = 3
myex = 100
ex = [ 101, 100, 400 ]
bonus = [100, 1, 524]

def fun(n, myex, ex, bonus):
    print(myex, ex, bonus)
    count = 0
    loop = 0
    for i in range(n):
        val = i
        for j in range(i, n):
            loop+=1
            val=j
            if(myex >= ex[j]):
                myex += bonus[j]
                tempx = ex[i]
                tempb = bonus[i]
                ex[i] = ex[j]
                ex[j] = tempx
                bonus[i] = bonus[j]
                bonus[j] = tempb
                count+=1
                #print(myex, ex, bonus)
                break
        if(val==n-1):
            #print(loop)
            return count


print(fun(n, myex, ex, bonus))
