n = 11
values = [1,2,3,4,5,6,7,8,9,10]

def output(val):
    if(val<5):
        return -1
    if (val-5)%3==0:
        return val-5
    return output(val-5)

def decentNumber(n):
    val = n
    if n <3:
        print(-1)
        return
    if n==5:
        print(33333)
        return
    if n%3==0:
        print(int("5"*n))
        return
    val = output(n)
    if(val==-1):
        print(-1)
    else:
        print(int("5"*val+"3"*(n-val)))


decentNumber(7)
# for i in values:
#     print(i,end=',')
#     decentNumber(i)
