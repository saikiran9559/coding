b1 = int(input())
h1 = int(input())
b2 = int(input())
h2 = int(input())
a1 = (b1*h1)/2
a2 = (b2*h2)/2
if(a1<a2):
    a1 = a2
print("{:.1f}".format(a1))
