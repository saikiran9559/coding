n = int(input())
b=0
g=0
d=0
a = n%26
if a<=2 and a>=0:
    b+=1
elif a<=3 and a>=10:
    g+=1
else:
    d+=1
print(b,g,d)
